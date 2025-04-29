#ifndef MISSION_H
#define MISSION_H

#include "map.h"
#include "config.h"
#include "xmlLogger.h"
#include "searchresult.h"
#include "aa_sipp.h"
#include "task.h"
#include "dynamicobstacles.h"

class Mission
{
public:
    Mission();      // 생성자
    ~Mission();     // 소멸자 

    bool getMap();
    bool getTask();
    bool getConfig();
    bool getObstacles();
    void createLog();
    void createSearch();                // AA_SIPP 객체 생성
    void startSearch();                 // 실제로 AA-SIPP로 탐색 시작
    void printSearchResultsToConsole();
    void saveSearchResultsToLog();
    void setFileNames(const char *taskName, const char* mapName, const char *configName, const char *obstaclesName);

private:
    Map              m_map;             // 격자 지도 정보
    Task             m_task;            // 시작점 - 도착점 정보 저장
    Config           m_config;          // XML 설정 정보
    DynamicObstacles m_obstacles;       // 동적 장애물
    AA_SIPP*         m_pSearch;         // AA-SIPP 알고리즘 객체 (포인터)
    XmlLogger*       m_pLogger;         // 탐색 결과를 로깅 (포인터)
    SearchResult     sr;                // 경로 탐색 결과 저장 (구조체)
    const char*      mapName;           // XML 파일 경로들 저장
    const char*      taskName;          // "
    const char*      configName;        // "
    const char*      obstaclesName;     // "

};

#endif

