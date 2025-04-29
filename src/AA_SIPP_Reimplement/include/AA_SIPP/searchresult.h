#ifndef SEARCHRESULT_H
#define SEARCHRESULT_H

#include <vector>
#include <list>
#include <structs.h>

struct ResultPathInfo
// 개별 agent의 경로에 대한 정보를 담음
{
    bool pathfound;                 // 전체적으로 탐색에 성공했는지 여부
    double pathlength;              // 경로의 총 거리
    double runtime;                 // 알고리즘 자체의 실행 시간
    std::list<Node> path;           // 경로에 해당하는 노드 리스트
    std::vector<Node> sections;     // 중요한 경유 지점들 

    ResultPathInfo()
    {
        runtime = 0;
        pathfound = false;
        pathlength = 0;
        path.clear();
        sections.clear();
    }
};

struct SearchResult
// 여러 agent의 탐색 결과 전체를 요약하는데 사용
{
    bool pathfound;         // 전체적으로 탐색에 성공했는지 여부
    double makespan;        // 마지막 agent가 도착한 시간
    double flowtime;        // 전체 agent의 소요 시간을 모두 합한 값
    double runtime;         // 알고리즘 자체의 실행 시간
    unsigned int agents;    // 전체 agent 수
    int agentsSolved;       // 실제로 경로가 계산된 agent 수
    int tries;              // 알고리즘이 시도한 횟수
    // 각 agent의 세부 경로 정보를 담은 ResultPathInfo 객체들
    std::vector<ResultPathInfo> pathInfo;

    SearchResult() : pathInfo(1) // pathInfo(1)로 초기화됨
    // 기본적으로 agent가 1대일 때의 결과를 다룰 준비
    {
        // 수치 초기화
        pathfound = false;
        runtime = 0;
        flowtime = 0;
        makespan = 0;
        agents = 0;
    }

    ~SearchResult()
    {
        pathInfo.clear();
    }

};

#endif // SEARCHRESULT_H
