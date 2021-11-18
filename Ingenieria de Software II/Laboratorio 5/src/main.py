#!/usr/bin/env python

from selenium import webdriver
from selenium.webdriver.common.keys import Keys
from time import sleep
from test import TestCalculator


test = TestCalculator('https://www.calculator.net/percent-calculator.html')

num1 = '10'
num2 = '40'
letters = 'AgB'
characters = '$*^1'
invalid1 = 'Ab23$%'
invalid2 = 'By52$%'

time_slepp = 2

test.all_test(num1, num2, time_slepp)
test.all_test(num1, letters, time_slepp)
test.all_test(num1, characters, time_slepp)
test.all_test(num1, '', time_slepp)
test.all_test(letters, num2, time_slepp)
test.all_test(characters, num2, time_slepp)
test.all_test('', num2, time_slepp)
test.all_test(invalid1, invalid2, time_slepp)
test.all_test('', '', time_slepp)