import unittest
from selenium import webdriver
from selenium.webdriver.common.keys import Keys
from time import sleep

class InputFormsCheck(unittest.TestCase):

    def setUp(self):
        self.browser = webdriver.Firefox()
        self.browser.get("https://www.calculator.net/percent-calculator.html")
        self.browser.maximize_window()
        self.browser.implicitly_wait(10)

    def PCalculator(self, num1, num2):
        var1 = self.browser.find_element_by_id('cpar1')
        var1.clear()
        var1.send_keys(num1)

        var2 = self.browser.find_element_by_id('cpar2')
        var2.clear()
        var2.send_keys(num2)

        submitButton = self.browser.find_elements_by_xpath("//input[@value='Calculate']")[0]
        submitButton.click()

        self.assertTrue(self.browser.find_element_by_class_name('h2result'))

    def PinCommon_1(self, num1, num2):
        var1 = self.browser.find_element_by_name('c21par1')
        var1.clear()
        var1.send_keys(num1)

        var2 = self.browser.find_element_by_name('c21par2')
        var2.clear()
        var2.send_keys(num2)

        submitButton = self.browser.find_elements_by_xpath("//input[@value='Calculate']")[1]
        submitButton.click()
        self.assertTrue(self.browser.find_element_by_class_name('h2result'))


    def PinCommon_2(self, num1, num2):
        var1 = self.browser.find_element_by_name('c22par1')
        var1.clear()
        var1.send_keys(num1)

        var2 = self.browser.find_element_by_name('c22par2')
        var2.clear()
        var2.send_keys(num2)

        submitButton = self.browser.find_elements_by_xpath("//input[@value='Calculate']")[2]
        submitButton.click()
        self.assertTrue(self.browser.find_element_by_class_name('h2result'))


    def PinCommon_3(self, num1, num2):
        var1 = self.browser.find_element_by_name('c23par1')
        var1.clear()
        var1.send_keys(num1)

        var2 = self.browser.find_element_by_name('c23par2')
        var2.clear()
        var2.send_keys(num2)

        submitButton = self.browser.find_elements_by_xpath("//input[@value='Calculate']")[3]
        submitButton.click()
        self.assertTrue(self.browser.find_element_by_class_name('h2result'))


    def PDiffCalculator(self, num1, num2):
        var1 = self.browser.find_element_by_name('c3par1')
        var1.clear()
        var1.send_keys(num1)

        var2 = self.browser.find_element_by_name('c3par2')
        var2.clear()
        var2.send_keys(num2)

        submitButton = self.browser.find_elements_by_xpath("//input[@value='Calculate']")[4]
        submitButton.click()
        self.assertTrue(self.browser.find_element_by_class_name('h2result'))


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
        self.assertTrue(self.browser.find_element_by_class_name('h2result'))


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
        self.assertTrue(self.browser.find_element_by_class_name('h2result'))


if __name__ == "__main__":
    unittest.main()