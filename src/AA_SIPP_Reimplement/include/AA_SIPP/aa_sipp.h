#ifndef AA_SIPP_H
#define AA_SIPP_H

#include "constraints.h"
#include "lineofsight.h"
#include "config.h"
#include "searchresult.h"
#include "task.h"
#include "dynamicobstacles.h"
#include <math.h>
#include <memory>
#include <algorithm>
#include <unordered_map>
#include <random>
#ifdef __linux__
    #include <sys/time.h>
#else
    #include <windows.h>
#endif
class AA_SIPP
{

public:

    AA_SIPP(const Config &config); // 생성자
    // 생성자는 설정 정보 Config만 저장
    ~AA_SIPP();
    // startSearch --> 핵심 함수
    // startSearch()는 Mission 클래스에서 실행되는 탐색 시작의 핵심
    SearchResult startSearch(Map &map, Task &task, DynamicObstacles &obstacles);
    // 반환값 타입은 SearchResult 형식 (클래스를 데이터 형식처럼 사용한 것)
    // 입력은 Map, Task, DynamicObstacles 레퍼런스들

    SearchResult sresult;

    // 이건 AA_SIPP 클래스의 멤버 변수

    // startSearch()에서 계산된 결과를 내부에 저장해두는 용도.
    
    // Mission 클래스에서는 이 sresult를 활용해서 출력하거나 로그를 저장.

    // --> GPT 답변
    // startSearch() 함수는 SearchResult 클래스 형식의 값을 반환하고, 
    // 내부적으로도 sresult라는 이름의 SearchResult 객체에 결과를 저장하므로, 
    // 우리는 이 함수가 탐색 결과를 표현하는 클래스가 SearchResult임을 명확히 알 수 있습니다.

private:

    // Open 리스트에 노드 추가
    void addOpen(Node &newNode);

    // Open 리스트에서 최소 F값 노드 선택
    Node findMin(int size);

    // 탐색 종료 조건 확인
    bool stopCriterion(const Node &curNode, Node &goalNode);
    
    // 현재 노드가 목표인지 판정
    bool testGoal(const Node &curNode, Node &goalNode);
    
    // 거리 및 회전 비용 계산
    double getCost(int a_i, int a_j, int b_i, int b_j);
    double getRCost(double headingA, double headingB);
    
    //
    double calcHeading(const Node &node, const Node &son);
    
    // 현재 노드에서 확장 가능한 노드 리스트 계산
    std::list<Node> findSuccessors(const Node curNode, const Map &map);
    
    // 경로 복원
    void makePrimaryPath(Node curNode);
    void makeSecondaryPath(Node curNode);
    
    // 
    void calculateLineSegment(std::vector<Node> &line, const Node &start, const Node &goal);
    
    // 
    void addConstraints(){}
    
    // 부모 노드 재성정(AA 경로용)
    Node resetParent(Node current, Node Parent, const Map &map);
    
    // 개별 에이전트 경로 탐색 수행
    bool findPath(unsigned int numOfCurAgent, const Map &map);
    
    // 에이전트 간 충돌 검사
    std::vector<conflict> CheckConflicts(const Task &task);//bruteforce checker. It splits final(already built) trajectories into sequences of points and checks distances between them
    
    // 우선 순위 설정
    void setPriorities(const Task &task);

    double getHValue(int i, int j);

    // 우선 순위 변경
    bool changePriorities(int bad_i);
    unsigned int openSize;

    std::list<Node> lppath;

    // 변수명: open --> std::vector<std::list<Node>> 구조의 Open 리스트(AA 구조)
    std::vector<std::list<Node>> open;

    // 변수명: close --> 중복 허용 해시맵.
    std::unordered_multimap<int, Node> close;

    // 변수명: lppath/hppath --> low-level/high-level path 저장용
    std::vector<Node> hppath;

    // 변수명: priorities/current_priorities --> 에이전트 간 우선순위 계산용
    std::vector<std::vector<int>> priorities;
    std::vector<int> current_priorities;

    // 변수명: lineofsight --> LOS 검사 도구 클래스
    LineOfSight lineofsight;

    // 변수명: curagent --> 현재 탐색 중인 에이전트 정보
    Agent curagent;

    // 변수명: constraints --> Safe Interval & 동적 장애물 제약 저장
    Constraints *constraints;

    // 변수명: config --> 설정값(공유 포인터)
    std::shared_ptr<const Config> config;
};

#endif // AA_SIPP_H
