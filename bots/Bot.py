import telebot
from telebot import types
from bs4 import BeautifulSoup as BS
from bs4 import BeautifulSoup
import requests
#DeHopen
TOKEN = '5395426736:AAE5IKGK82_YCEHlxfktgPvhxUYaNJc8kz4'
doll = 'https://www.google.com/search?sxsrf=ALeKk01NWm6viYijAo3HXYOEQUyDEDtFEw%3A1584716087546&source=hp&ei=N9l0XtDXHs716QTcuaXoAg&q=%D0%B4%D0%BE%D0%BB%D0%BB%D0%B0%D1%80+%D0%BA+%D1%80%D1%83%D0%B1%D0%BB%D1%8E&oq=%D0%B4%D0%BE%D0%BB%D0%BB%D0%B0%D1%80+&gs_l=psy-ab.3.0.35i39i70i258j0i131l4j0j0i131l4.3044.4178..5294...1.0..0.83.544.7......0....1..gws-wiz.......35i39.5QL6Ev1Kfk4'
euro = 'https://www.google.com/search?q=евро+к+рублю&sxsrf=ALiCzsZfpTDUjvoPF2rtg4CfBh6o8vkAyQ%3A1651997130857&ei=ynl3YtqCNIX6rgS_8rSYDw&oq=доллар+кC+рублю&gs_lcp=Cgdnd3Mtd2l6EAEYATIHCCMQsAMQJzIHCAAQRxCwAzIHCAAQRxCwAzIHCAAQRxCwAzIHCAAQRxCwAzIHCAAQRxCwAzIHCAAQRxCwAzIKCAAQRxCwAxDJAzIHCAAQRxCwAzIHCAAQsAMQQ0oECEEYAEoECEYYAFAAWABgtiBoAnABeACAAQCIAQCSAQCYAQDIAQrAAQE&sclient=gws-wiz'
headers = {'User-Agent': 'Mozilla/5.0 (Macintosh; Intel Mac OS X 10_15_3) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/80.0.3987.149 Safari/537.36'}
msk = 'https://time100.ru/Moscow'
kmr = 'https://time100.ru/kemerovo'
w = 'https://rusmeteo.net/weather/kemerovo/'
fx = 'https://randomfox.ca/' 

bot = telebot.TeleBot(TOKEN)

@bot.message_handler(commands=['start'])
def start(message):
    markup = types.ReplyKeyboardMarkup(resize_keyboard = True)
    item1 = types.KeyboardButton('Курсы валют')
    item2 = types.KeyboardButton('Погода')
    item3 = types.KeyboardButton('Фото лисы')
    item4 = types.KeyboardButton('Сайт КемГУ')
    markup.add(item1, item2, item3, item4)
    bot.send_message(message.chat.id, 'Привет, {0.first_name}!\nВыберите внизу нужную команду\n'.format(message.from_user), reply_markup = markup)
@bot.message_handler(content_types=['text'])
def bot_message(message):
    if message.chat.type == 'private':
        if message.text == 'Курсы валют':
            markup = types.ReplyKeyboardMarkup(resize_keyboard=True)
            item1 = types.KeyboardButton('Курс Доллара')
            item2 = types.KeyboardButton('Курс Евро')
            back = types.KeyboardButton('Назад')
            markup.add(item1, item2, back)
            bot.send_message(message.chat.id, 'Выберите валюту', reply_markup=markup)
        elif message.text == 'Назад':
            markup = types.ReplyKeyboardMarkup(resize_keyboard=True)
            item1 = types.KeyboardButton('Курсы валют')
            item2 = types.KeyboardButton('Погода')
            item3 = types.KeyboardButton('Фото лисы')
            item4 = types.KeyboardButton('Сайт КемГУ')
            markup.add(item1, item2, item3, item4)
            bot.send_message(message.chat.id, 'Назад', reply_markup=markup)
        elif message.text == 'Курс Доллара':
            dollar(message)
        elif message.text == 'Курс Евро':
            evro(message)
        elif message.text == 'Фото лисы':
            img(message)
        elif message.text == 'Погода':
            full_page = requests.get(w, headers=headers)
            html = BS(full_page.content, 'html.parser')
            convert = html.findAll("div", {"class": "weather-text"})
            bot.send_message(message.chat.id, convert[0].text)
        elif message.text == 'Сайт КемГУ':
            site(message)

def dollar(message):
    full_page = requests.get(doll, headers=headers)
    soup = BeautifulSoup(full_page.content, 'html.parser')
    convert = soup.findAll("span", {"class": "DFlfde", "class": "SwHCTb", "data-precision": 2})
    bot.send_message(message.chat.id, "1$ = " + convert[0].text)
def evro(message):
    full_page = requests.get(euro, headers=headers)
    soup = BeautifulSoup(full_page.content, 'html.parser')
    convert = soup.findAll("span", {"class": "DFlfde", "class": "SwHCTb", "data-precision": 2})
    bot.send_message(message.chat.id, "1€ = " + convert[0].text)
def site(message):
    markup = types.InlineKeyboardMarkup()
    button = types.InlineKeyboardButton("Сайт КемГУ", url='https://kemsu.ru/')
    markup.add(button)
    bot.send_message(message.chat.id, "Перейдите по ссылке".format(message.from_user), reply_markup=markup)
def img(message):
    bot.send_photo(message.chat.id,fx)
if __name__ == '__main__':
    bot.polling(none_stop=True)