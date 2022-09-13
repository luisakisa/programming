package com.company.view.online;

import com.company.view.Info;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.ProgressIndicator;
import javafx.scene.control.TextField;
import javafx.scene.input.KeyEvent;

import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.nio.charset.StandardCharsets;

import javafx.application.Platform;

public class OnlineController{
    @FXML
    private Button backBtn;

    @FXML
    private Button connectBtn;

    @FXML
    private TextField ipField;

    @FXML
    private TextField loginField;

    @FXML
    private Label connectionInfo;

    @FXML
    ProgressIndicator indicator;

    private boolean ipCorrect;

    private boolean loginCorrect;

    @FXML
    public void initialize(){
        ipCorrect = true;
        loginCorrect = false;
    }

    @FXML
    private void writeLogin(KeyEvent event){
        if(loginField.getText().matches("^[a-z0-9]+")){
            loginCorrect = true;
            if(ipCorrect){
                connectBtn.setDisable(false);
            }
        }
        else {
            loginCorrect = false;
            connectBtn.setDisable(true);
        }
    }

    @FXML
    private void writeIP(KeyEvent event){
        if(ipField.getText().matches("([0-9]{1,3}[\\.]){3}[0-9]{1,3}")){
            ipCorrect = true;
            if(loginCorrect){
                connectBtn.setDisable(false);
            }
        }
        else{
            ipCorrect = false;
            connectBtn.setDisable(true);
        }
    }

    @FXML
    private void clickBackBtn(ActionEvent event) throws Exception{
        Info.ip = "";
        Info.name = "";
        Scene theScene = backBtn.getScene();
        Parent theRoot = FXMLLoader.load(getClass().getResource("../main/MainView.fxml"));
        theScene.setRoot(theRoot);
    }

    @FXML
    private void clickConnectBtn(ActionEvent event) throws Exception{
        Info.ip = ipField.getText();
        Info.name = loginField.getText();
        connectionInfo.setVisible(false);
        indicator.setVisible(true);
        try {
            new Thread(new Runnable()
            {
                @Override
                public void run(){
                    try {
                        DatagramSocket socket = new DatagramSocket(Info.clientPort);
                        byte[] buffer = new byte[1000 * 32];
                        DatagramPacket packet = new DatagramPacket(buffer, buffer.length);

                        byte[] bufferSend = "{\"type\": \"check\"}".getBytes(StandardCharsets.UTF_8);
                        DatagramPacket request = new DatagramPacket(bufferSend, bufferSend.length, InetAddress.getByName(ipField.getText()), Info.serverPort);
                        socket.send(request);

                        new Thread(new Runnable() {
                            @Override
                            public void run() {
                                try {
                                    Thread.currentThread().sleep(3000);
                                    socket.close();
                                }
                                catch (Exception e){}
                            }
                        }).start();

                        socket.receive(packet);
                        if(!socket.isClosed()) socket.close();

                        Platform.runLater(new Runnable() {
                            public void run() {
                                try {
                                    Scene theScene = connectBtn.getScene();
                                    Parent theRoot = FXMLLoader.load(getClass().getResource("../game/GameView.fxml"));
                                    theScene.setRoot(theRoot);
                                }
                                catch(Exception e){
                                    System.out.println("Ошибка в смене сцены: " + e.getMessage());
                                }
                            }
                        });
                    }
                    catch (Exception e){
                        System.out.println(e.getMessage());
                        Platform.runLater(new Runnable() {
                            public void run() {
                                indicator.setVisible(false);
                                connectionInfo.setVisible(true);
                            }
                        });
                    }
                }
            }).start();
        }
        catch (Exception e){
            System.out.println("Ошибка при создании потока подключения: " + e.getMessage());
        }
    }
}
