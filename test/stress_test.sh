#!/bin/bash

# 컴파일 C++ 코드
g++ -o main main.cpp
g++ -o naive naive.cpp

# 테스트 반복 횟수
for ((i = 1; i <= 1000; i++)); do
    # echo "테스트 케이스 $i 생성 중..."

    # 테스트 케이스 생성
    python3 tcgenerator.py > input.txt

    # 두 프로그램 실행
    ./main < input.txt > output_main.txt
    ./naive < input.txt > output_naive.txt

    # 결과 비교
    if diff output_main.txt output_naive.txt > /dev/null; then
        echo "테스트 케이스 $i: 성공"
    else
        echo "테스트 케이스 $i: 실패"
        echo "입력 파일:"
        cat input.txt
        echo "main 출력:"
        cat output_main.txt
        echo "naive 출력:"
        cat output_naive.txt
        break
    fi
done
