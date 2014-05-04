# -*- coding: utf-8 -*-
import requests
from lxml import etree

#使用requests库的get方法发起请求
headers = {"X-Requested-With" : "XMLHttpRequest"}
url = 'http://www.newsmth.net/nForum/board/HouseRent'
r = requests.get(url,headers=headers)

#网页文本内容
htmlContent = r.text


#建立HTML DOM tree
page = etree.HTML(htmlContent)

#用于解析的一些东西，解析title和href
baseUrl = "http://www.newsmth.net"
hrefRule = "//div[@class='b-content']/table/tbody/tr/td[2]/a/@href"
titleRule = "//div[@class='b-content']/table/tbody/tr/td[2]/a"
parseResults_href = page.xpath(hrefRule.decode('utf-8'))
parseResults_title = page.xpath(titleRule.decode('utf-8'))



#暴力查找，然后输出title和href
for i in range(len(parseResults_title)):
    if parseResults_title[i].text.encode("utf-8").find("西二旗") != -1:
        print "---------"
        print parseResults_title[i].text
        print baseUrl + parseResults_href[i]
