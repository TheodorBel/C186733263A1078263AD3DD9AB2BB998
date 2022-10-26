from bs4 import BeautifulSoup
import requests
import json
import time
import csv
import xlrd
import xlwt


url = 'https://stopgame.ru/topgames?rating=izumitelno&p=1' #Нужный сайт
print(time.ctime(), "start")
pages = 1

while(1):
    
    response = requests.get(url)
    soup = BeautifulSoup(response.text, 'lxml') #Парсинг
    vars = soup.find_all(class_ = "caption caption-bold") #выбор нужного
    nextpage = soup.find(class_ = "next") #Ссылка на следующий раздел 

    
    
    if nextpage:
        with open("test.json", "a") as file:
            file.write(json.dumps([str((var.text).strip()) for var in vars], indent= 4)) #Открываю файл и записываюc
        
        
        with open('test.csv', 'a', newline='') as csvfile:
            testwriter = csv.writer(csvfile, delimiter='\n',
                            quotechar='|', quoting=csv.QUOTE_MINIMAL)
            testwriter.writerow([str((var.text).strip()) for var in vars])
        
            
            nextpage = "https://stopgame.ru" + nextpage.get("href")
            url = nextpage
            pages += 1
            continue
        
        
        

        
        
        
    print(time.ctime(), "done")
    print("pages:", pages)
    break    