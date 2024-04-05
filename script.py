import sys
import os

test = []


def get_test(n):
    test = []
    with open(f"p1_tests/{n}.out") as f:
        lines = f.readlines()
        lines = [l.strip() for l in lines]
        for i in range(len(lines)):
            if lines[i] == "":
                test.append(lines[i + 1])
    return test

def delete_files():
    for i in range(10):
        try:
            os.remove(f"p1_tests/{i}.my")
        except:
            pass

def get_my(n):
    with open(f"p1_tests/{n}.my") as f:
        lines = f.readlines()
        my = [l.strip() for l in lines]
        return my


if __name__ == "__main__":
    passed = []

    for L in range(0, 10):
        try:
            os.system(f"cmake-build-debug/project1 < p1_tests/{L}.in > p1_tests/{L}.my")
            test = get_test(L)
            my = get_my(L)
            err = 0
            for i in range(0, len(test)):
                if test[i] != my[i]:
                    err += 1
                    print(f"[{L}] ({i + 2}) NOT OK")
                elif test[i] == my[i]:
                    print(f"[{L}] ({i + 2}) OK")
            if err == len(test):
                print(f"[{L}] all error")
            if err == 0:
                passed.append(L)
                print(f"[{L}] passed")
        except Exception as e:
            print(f"[{L}] ({i + 2}) <--- ERROR occured {test[i][:25]}")
            print(e)
        print()

for i in range(10):
    if i in passed:
        print(f"[{i}] ", end="")
    else:
        print(f"_{i}_ ", end="")
