from email.utils import localtime
from aiogram import Bot, types
from aiogram.dispatcher import Dispatcher
from aiogram.utils import executor
import time
from datetime import date

from config import TOKEN


bot = Bot(token=TOKEN)
dp = Dispatcher(bot)
t = time.localtime()


@dp.message_handler(commands=['time'])
async def process_time_command(message: types.Message):
    await message.reply(time.strftime("%H:%M:%S", t))
    
@dp.message_handler(commands=['date'])
async def process_time_command(message: types.Message):
    await message.reply(date.today())


@dp.message_handler(commands=['help'])
async def process_help_command(message: types.Message):
    await message.reply("Набери команду /time, чтобы получить время или /date, чтобы получить дату")



if __name__ == '__main__':
    executor.start_polling(dp)