import turtle


def triangle (size, t, quant = 1):
    if(quant > 0):
        t.pendown()
        for i in range(quant):
            t.begin_fill()
            t.penup()
            t.forward(size)
            t.pendown()
            t.left(120)
            t.forward(size)
            t.left(120)
            t.forward(size)
            t.penup()
            t.left(120)
            t.forward(size)
            t.end_fill()
        t.penup()
        t.left(120)
        t.forward(size/2)
        t.left(60)
        t.forward(size*(quant-0.75))
        t.right(180)
        triangle(size, t, quant-1)


t = turtle.Turtle()
t.penup()
t.fillcolor("grey")
t.goto(-500, -450)
t.pendown()
t.speed(1000)
myWin = turtle.Screen()
triangle(200, t, 5)

myWin.exitonclick()
