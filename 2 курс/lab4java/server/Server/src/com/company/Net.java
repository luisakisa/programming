package com.company;

import java.net.*;
import java.io.*;

class Net
{
    public static void main(String args[]) throws IOException {

        ServerSocket ss = new ServerSocket(1111);
        System.out.println("Сервер запущен!");
        while (true){
            try
            {
                Socket client = ss.accept();
                System.out.println("Клиент подключился");

                try {
                    BufferedReader in = new BufferedReader(new InputStreamReader(client.getInputStream()));
                    BufferedWriter out = new BufferedWriter(new OutputStreamWriter(client.getOutputStream()));


                    while (true)
                    {
                        int sign = in.read();
                        int a = in.read();
                        int b = in.read();
                        System.out.println(a);
                        System.out.println(b);
                        if(sign == 1)
                        {
                            int n = a + b;
                            out.write(n);
                        }
                        else if(sign == 2){
                            int n = a - b;
                            out.write(n);
                        }
                        else if(sign == 3){
                            int n = a * b;
                            out.write(n);
                        }
                        else if(sign == 4){
                            int n = a / b;
                            out.write(n);
                        }
                        else {
                            int n = 1;
                            for(int i = 0; i<b; i++)
                            {
                                n*=a;
                            }
                            out.write(n);
                        }
                        out.flush();
                    }
                } catch (IOException e) {
                    e.printStackTrace();

                }


            }
            catch (Exception e)
            {
                System.out.println("Error: " + e);
            }
        }

    }
}