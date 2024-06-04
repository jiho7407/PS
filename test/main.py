import sys
import subprocess


def generate_input():
    subprocess.run(["python", "TCGenerator.py"])


def run_python_script():
    result = subprocess.run(["python", "test.py"],
                            capture_output=True, text=True)
    return result.stdout.strip()


def run_cpp_program():
    subprocess.run(["g++", "-o", "test", "test.cpp"])
    result = subprocess.run(["./test.exe"], capture_output=True, text=True)
    return result.stdout.strip()


def run_cpp_program2():
    subprocess.run(["g++", "-o", "test", "test2.cpp"])
    result = subprocess.run(["./test2.exe"], capture_output=True, text=True)
    return result.stdout.strip()


def compare_results(result1, result2):
    if result1 == result2:
        # print(f"AC: {result1}")
        print("OK")
    else:
        # print(f"result1:{result1}, result2: {result2}")
        print("WA")
        sys.exit()


if __name__ == "__main__":
    while 1:
        # 입력 파일 생성
        generate_input()
        print("Input.txt 생성 완료", end=" ")

        # 파이썬 스크립트 실행
        # python_result = run_python_script()

        # C++ 프로그램 컴파일 및 실행
        cpp_result = run_cpp_program()
        cpp_result2 = run_cpp_program2()

        # 결과 비교
        compare_results(cpp_result, cpp_result2)

"""
ifstream cin("D:\\Programming-D\\PS\\test\\input.txt");
다는것 잊지 말기
"""
