#!/usr/bin/python3
import sys
import os

problem_name = sys.argv[1]
problem_folder = problem_name + '_inf/'
testcases_folder = os.path.join(problem_folder, 'data', 'secret')

def get_files_by_ext(testcases: list[str], ext: str) -> list[str]:
    return list(filter(lambda filename: filename.endswith(ext), testcases))

# def group_testcases(testcases: list[str]):

testcases = os.listdir(testcases_folder)

testcases = group_testcases(testcases)
