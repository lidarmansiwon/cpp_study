#include"mission.h"

Mission::Mission()
{
    m_pSearch = nullptr;
    m_pLogger = nullptr;
}

Mission::~Mission()
{
    delete m_pSearch;
    delete m_pLogger;
}

// 내부적으로 단순히 const char* 포인터에 XML 파일 경로를 저장.
void Mission::setFileNames(const char *taskName, const char *mapName, const char *configName, const char *obstaclesName)
{
    this->mapName = mapName;
    this->taskName = taskName;
    this->configName = configName;
    this->obstaclesName = obstaclesName;
}

// XML 파일들 로딩 함수 시작
bool Mission::getMap()
{
    return m_map.getMap(mapName);
}

bool Mission::getTask()
{
    return (m_task.getTask(taskName) && m_task.validateTask(m_map));
}

bool Mission::getConfig()
{
    return m_config.getConfig(configName);
}

bool Mission::getObstacles()
{
    if(obstaclesName)
        return m_obstacles.getObstacles(obstaclesName);
    else
        return false;
}
// XML 파일들 로딩 함수 종료

void Mission::createSearch()
{
    if(m_pSearch)
    {
        delete m_pSearch;
        delete m_pLogger;
    }
    m_pSearch = new AA_SIPP(m_config);
}

void Mission::createLog()
{
    if(m_config.loglevel != CN_LOGLVL_NO)
    {
        m_pLogger = new XmlLogger(m_config.loglevel);
        m_pLogger->createLog(taskName);
    }
}

void Mission::startSearch()
{
    //std::cout<<"SEARCH STARTED\n";
    sr = m_pSearch->startSearch(m_map, m_task, m_obstacles);
}

void Mission::printSearchResultsToConsole()
{
    //std::cout<<bool(sr.agentsSolved/sr.agents)<<" "<<sr.time<<" "<<sr.makespan<<" "<<sr.pathlength<<" "<<sr.flowlength<<"\n";
    std::cout<<"Results:\nTask solved: "<<bool(sr.agentsSolved/sr.agents)<<"\nTries: "<<sr.tries<<"\nRuntime: "<<sr.runtime<<"\nAgents solved: "<<sr.agentsSolved<<" ("<<(float)sr.agentsSolved*100/sr.agents<<"%)\nFlowtime: "<<sr.flowtime<<"\nMakespan: "<<sr.makespan<<"\n";
}

void Mission::saveSearchResultsToLog()
{
    if(m_config.loglevel == CN_LOGLVL_NO)
        return;
    std::cout<<"LOG STARTED\n";
    m_pLogger->writeToLogInput(taskName, mapName, configName, obstaclesName);
    m_pLogger->writeToLogSummary(sr);
    if(sr.pathfound)
    {
        m_pLogger->writeToLogMap(m_map, sr);
        m_pLogger->writeToLogPath(sr, m_task, m_config);
    }
    m_pLogger->saveLog();
    std::cout<<"LOG SAVED\n";
}

