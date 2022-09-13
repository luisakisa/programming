import asyncio
import nest_asyncio
import discord
from discord.ext import commands
from config import settings

nest_asyncio.apply()
bot = commands.Bot(command_prefix=('/'))
client = discord.Client()

@client.event
async def on_ready():
    print('Я подключился и готов показать котика или песика')

@client.event
async def on_message(message):
    if "кот" in message.content.lower():
        await message.channel.send(file=discord.File('C:\\Users\\rfnzt\\Downloads\car.png'))
    if "собак" in message.content.lower():
           await message.channel.send(file=discord.File('C:\\Users\\rfnzt\\Downloads\\dog-clip-art-royalty-free-animal-images-animal-clipart-org-709485.png'))
@bot.command()
async def timer(message, seconds):
    await asyncio.sleep(int(seconds))
    await message.channel.send(f'Время {seconds} наступило')
   

client.run(settings['token'])