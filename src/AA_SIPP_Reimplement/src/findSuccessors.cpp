std::list<Node> AA_SIPP::findSuccessors(const Node curNode, const Map &map)
{
    Node newNode, angleNode; // newNode : 새로운 후속 노드를 저장하기 위한 변수, angleNode : 각도와 관련된 후속 노드를 위한 변수. 
    std::list<Node> successors; // successors: 후속 노드를 저장하는 리스트.
    std::vector<double> EAT; // EAT: 예상 경로 시간을 저장할 벡터
    std::vector<SafeInterval> intervals; // intervals: 안전 구간(SafeIntervals) 을 계산하여 저장할 벡터.
    double h_value; // h_value: 후속 노드의 휴리스틱 값을 저장할 변수.
    auto parent = &(close.find(curNode.i*map.width + curNode.j)->second);
    std::vector<Node> moves = map.getValidMoves(curNode.i, curNode.j, config->connectedness, curagent.size); // moves: 가능한 이동 방향들을 얻기 위한 함수 호출. map.getValidMoves() 함수는 현재 위치에서 이동할 수 있는 유효한 방향을 반환
    double angle_difference;
    for(auto m:moves)  // moves 벡터에서 하나씩 꺼내어 가능한 이동을 확인
        if(lineofsight.checkTraversability(curNode.i + m.i,curNode.j + m.j,map))  // lineofsight.checkTraversability는 이동하려는 위치가 장애물이 없는지, 이동할 수 있는지 확인
        {
            // 새로운 노드 정보 업데이트
            newNode.i = curNode.i + m.i;
            newNode.j = curNode.j + m.j;
            constraints->updateCellSafeIntervals({newNode.i,newNode.j});
            newNode.heading = calcHeading(curNode, newNode);

            // **(추가) 회전각 50도 제한 적용** ------------------------------ //
            {
                double oldHeading = curNode.heading;  // 부모 노드의 heading
                double newHeading = newNode.heading;
                double turn = fabs(newHeading - oldHeading);

                // (예: 350도 - 10도 = 340도, 실제로는 20도 회전)
                if(turn > 180.0)
                    turn = 360.0 - turn;

                // std::cout<< "angle: " << turn << "\n"<< std::endl;
                // // 50도 초과면 무효 처리
                if(turn > 90.0) {
                    // std::cout<< "angle: " << turn << "\n"<< std::endl;
                    continue; // 유효 후보에서 제외
                }
            }

            angleNode = curNode; //the same state, but with extended g-value
            angleNode.g += getRCost(angleNode.heading, newNode.heading) + config->additionalwait;//to compensate the amount of time required for rotation
            newNode.g = angleNode.g + m.g/curagent.mspeed;
            newNode.Parent = &angleNode;
            h_value = getHValue(newNode.i, newNode.j);

            if(angleNode.g <= angleNode.interval.end)
            {
                intervals = constraints->findIntervals(newNode, EAT, close, map);
                for(unsigned int k = 0; k < intervals.size(); k++)
                {
                    newNode.interval = intervals[k];
                    newNode.Parent = parent;
                    newNode.g = EAT[k];
                    newNode.F = newNode.g + h_value;
                    successors.push_front(newNode);
                }
            }
            
            if(config->allowanyangle)
            {
                newNode = resetParent(newNode, curNode, map);
                if(newNode.Parent->i != parent->i || newNode.Parent->j != parent->j)
                {
                    angleNode = *newNode.Parent;
                    newNode.heading = calcHeading(*newNode.Parent, newNode);//new heading with respect to new parent
                    angleNode.g += getRCost(angleNode.heading, newNode.heading) + config->additionalwait;//count new additional time required for rotation
                    newNode.g += getRCost(angleNode.heading, newNode.heading) + config->additionalwait;
                    newNode.Parent = &angleNode;
                    if(angleNode.g > angleNode.interval.end)
                        continue;
                    intervals = constraints->findIntervals(newNode, EAT, close, map);
                    for(unsigned int k = 0; k < intervals.size(); k++)
                    {
                        newNode.interval = intervals[k];
                        newNode.Parent = parent->Parent;
                        newNode.g = EAT[k];
                        newNode.F = newNode.g + h_value;
                        successors.push_front(newNode);
                    }
                }
            }
        }

    return successors;
}