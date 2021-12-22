#!/usr/bin/env python

from selenium import webdriver
from selenium.webdriver.common.keys import Keys
from time import sleep

class TestCalculator:

    def __init__(self, link):
        self.browser = webdriver.Firefox()
        self.browser.get(link)


    def PCalculator(self, num1, num2):
        var1 = self.browser.find_element_by_id('cpar1')
        var1.clear()
        var1.send_keys(num1)

        var2 = self.browser.find_element_by_id('cpar2')
        var2.clear()
        var2.send_keys(num2)

        submitButton = self.browser.find_elements_by_xpath("//input[@value='Calculate']")[0]
        submitButton.click()


    def PinCommon_1(self, num1, num2):
        var1 = self.browser.find_element_by_name('c21par1')
        var1.clear()
        var1.send_keys(num1)

        var2 = self.browser.find_element_by_name('c21par2')
        var2.clear()
        var2.send_keys(num2)

        submitButton = self.browser.find_elements_by_xpath("//input[@value='Calculate']")[1]
        submitButton.click()


    def PinCommon_2(self, num1, num2):
        var1 = self.browser.find_element_by_name('c22par1')
        var1.clear()
        var1.send_keys(num1)

        var2 = self.browser.find_element_by_name('c22par2')
        var2.clear()
        var2.send_keys(num2)

        submitButton = self.browser.find_elements_by_xpath("//input[@value='Calculate']")[2]
        submitButton.click()


    def PinCommon_3(self, num1, num2):
        var1 = self.browser.find_element_by_name('c23par1')
        var1.clear()
        var1.send_keys(num1)

        var2 = self.browser.find_element_by_name('c23par2')
        var2.clear()
        var2.send_keys(num2)

        submitButton = self.browser.find_elements_by_xpath("//input[@value='Calculate']")[3]
        submitButton.click()


    def PDiffCalculator(self, num1, num2):
        var1 = self.browser.find_element_by_name('c3par1')
        var1.clear()
        var1.send_keys(num1)

        var2 = self.browser.find_element_by_name('c3par2')
        var2.clear()
        var2.send_keys(num2)

        submitButton = self.browser.find_elements_by_xpath("//input[@value='Calculate']")[4]
        submitButton.click()


    def PChange_Decrease(self, num1, num2):
        var1 = self.browser.find_element_by_name('c2par1')
        var1.clear()
        var1.send_keys(num1)

        var2 = self.browser.find_element_by_name('c2par2')
        var2.clear()
        var2.send_keys(num2)

        self.browser.find_element_by_xpath("//select[@name='c2type']/option[text()='Decrease']").click()

        submitButton = self.browser.find_elements_by_xpath("//input[@value='Calculate']")[5]
        submitButton.click()


    def PChange_Increase(self, num1, num2):
        var1 = self.browser.find_element_by_name('c2par1')
        var1.clear()
        var1.send_keys(num1)

        var2 = self.browser.find_element_by_name('c2par2')
        var2.clear()
        var2.send_keys(num2)

        self.browser.find_element_by_xpath("//select[@name='c2type']/option[text()='Increase']").click()

        submitButton = self.browser.find_elements_by_xpath("//input[@value='Calculate']")[5]
        submitButton.click()


    def all_test(self, a, b, time_sleep):
        self.PCalculator(a, b)
        sleep(time_sleep)
        self.PinCommon_1(a, b)
        sleep(time_sleep)
        self.PinCommon_2(a, b)
        sleep(time_sleep)
        self.PinCommon_3(a, b)
        sleep(time_sleep)
        self.PDiffCalculator(a, b)
        sleep(time_sleep)
        self.PChange_Increase(a, b)
        sleep(time_sleep)
        self.PChange_Decrease(a, b)
        sleep(time_sleep)