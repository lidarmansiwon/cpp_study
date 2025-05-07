# 📘 cpp_study

C++ 언어와 ROS 2 C++ 프로그래밍을 함께 공부하는 저장소입니다.  
공부하며 작성한 소스 코드들을 저장해놓았습니다. 
공부하며 작성한 이론 정리들은 아래 블로그에 모두 저장되어있습니다. 

https://lidarmansiwon.tistory.com/category/%EA%B0%9C%EB%B0%9C%20%EC%96%B8%EC%96%B4/C%2B%2B


- **C++ 기초부터 심화까지** : "C++ 완전 정복" 책 기반으로 실습
- **ROS 2 C++ 프로그래밍** : Publisher / Subscriber 등 ROS2 핵심 코드 학습

---

## 📂 폴더 구조
```cpp_study
└── src
    ├── basic_pub_sub
    │   ├── cpp_basic_pub.cpp        # ROS2 Publisher 기본 예제
    │   └── cpp_basic_sub.cpp        # ROS2 Subscriber 기본 예제
    └── cpp_do_it
        └── chapter.02
            └── 변수와 연산자
        └── chapter.03
            └── 포인터와 메모리 구조
        └── chapter.04
            └── 실행 흐름 제어
        └── chapter.05
            └── 예외처리
        └── chapter.06
            └── 객체지향과 클래스
        └── chapter.07
            └── 
        └── chapter.08
            └── 

```
- `cpp_do_it/` : 📖 **C++ 완전 정복** 책 실습 코드 저장
- `basic_pub_sub/` : 🌐 ROS 2 기본 Publish / Subscribe 예제 코드
- 앞으로 다른 ROS 2 예제 및 C++ 심화 예제들도 이 구조로 추가 예정입니다!

---

## 🚀 빌드 & 실행 방법

### 1. colcon 빌드

```bash
cd ~/study_ws  # 작업 중인 ROS2 워크스페이스
colcon build --packages-select cpp_study
source install/setup.bash

# 설치된 실행 파일
./install/cpp_study/lib/cpp_study/implicit_cast

# 또는 build 디렉토리에서 바로 실행
./build/cpp_study/implicit_cast
