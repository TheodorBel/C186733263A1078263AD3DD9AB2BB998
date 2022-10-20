from bs4 import BeautifulSoup
import requests
import json


url = 'https://stopgame.ru/topgames?rating=izumitelno&p=1' #Нужный сайт
response = requests.get(url)
soup = BeautifulSoup(response.text, 'lxml') #Парсинг
vars = soup.find_all(class_ = "caption caption-bold") #выбор нужного 
    
with open("test.json", "w") as file:
    file.write(json.dumps([str((var.text).strip()) for var in vars], indent= 4)) #Открываю файл и записываю