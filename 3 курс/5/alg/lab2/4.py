import turtle


size = 300
n = 2


def koch_curve(size, n):
    if n == 0:
        turtle.forward(size)
    else:
        koch_curve(size / 3, n - 1)
        turtle.left(60)
        koch_curve(size / 3, n - 1)
        turtle.right(120)
        koch_curve(size / 3, n - 1)
        turtle.left(60)
        koch_curve(size / 3, n - 1)


def draw_koch_snowflake(size, n):
    myWin = turtle.Screen()
    for i in range(3):
        koch_curve(size, n)
        turtle.right(120)
    myWin.exitonclick()


draw_koch_snowflake(size, n)