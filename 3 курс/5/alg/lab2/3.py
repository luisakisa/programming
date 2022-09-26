import random
import turtle


def tree(branchLen, t):
    if branchLen > 9:
        t.color("brown")
        t.pensize(branchLen/10) # Изменяет толщину ветвей, чтобы при уменьшении branchLen линии становились тоньше
        t.forward(branchLen)
        rnd = random.uniform(0.3, 0.9)  # Изменяет угол поворота черепахи, чтобы каждая ветвь поворачивалась  произвольным образом в некотором диапазоне.
        t.right(branchLen * rnd)
        rand = random.randint(5, 10) # Измените рекурсивную часть branchLen, чтобы каждый раз вычиталось  произвольное значение из некоторого диапазона вместо некой постоянной  величины.
        tree(branchLen - rand, t)
        t.left(branchLen * rnd * 2)
        tree(branchLen - rand, t)
        t.right(branchLen * rnd)
        t.color("green") # Измените цвет ветвей таким образом, чтобы самые короткие ветви окрашивались как листья
        t.backward(branchLen)


t = turtle.Turtle()
t.speed(1000)
myWin = turtle.Screen()
t.left(90)
t.up()
t.backward(100)
t.down()
t.color("brown")
tree(50, t)
myWin.exitonclick()
