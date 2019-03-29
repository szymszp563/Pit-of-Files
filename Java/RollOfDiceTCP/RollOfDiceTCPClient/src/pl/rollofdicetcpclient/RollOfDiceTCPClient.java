/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pl.rollofdicetcpclient;

import java.net.*;
import java.io.*;
import java.util.Scanner;


/** 
 * The main UDP client class 
 * 
 * @author Szymon Szpakowski
 * @version 3.1
 */
public class RollOfDiceTCPClient {

    /** communication socket */
    private Socket socket;
    /** server port number  */
    int PORT;
    /** server address */
    private InetAddress serverAddress;
    /** a client id */
    private int id;
     /**
     * buffered input character stream
     */
    private BufferedReader input;
    /**
     * Formatted output character stream
     */
    private PrintWriter output;

 
    /**
     * contructor of TCP Client
     * @param id
     * @param serverAddress
     * @param serverPort 
     * @throws java.io.IOException 
     */
    public RollOfDiceTCPClient(int id, InetAddress serverAddress, int serverPort) throws IOException {
        this.id = id;
        this.PORT = serverPort;
        this.serverAddress = serverAddress;//InetAddress.getByName("localhost");
        this.socket = new Socket(this.serverAddress, this.PORT);
        
        System.out.println("Client " + id + " started");
    }

    /**
     * Method that starts communication with server
     * @throws java.io.IOException
     */
    public void start() throws IOException {
        this.output = new PrintWriter(
                    new BufferedWriter(
                            new OutputStreamWriter(
                                    socket.getOutputStream())), true);
        this.input = new BufferedReader(
                    new InputStreamReader(
                            socket.getInputStream()));
        Scanner scanner = new Scanner(System.in);
        
        while(true){
            try {
            //String outMessage = "3";
            String inMessage = input.readLine();
            while(input.ready()){
                inMessage +="\n";
                inMessage += input.readLine();
            }
            System.out.println(inMessage);
            
            output.println(scanner.next());
            String inMessage2 = input.readLine();
            
            System.out.println(inMessage2);
            inMessage2 = input.readLine();
            System.out.println(inMessage2);
            
            output.println(scanner.next());
            
            String inMessage3 = input.readLine();
            System.out.println(inMessage3);
            inMessage3 = input.readLine();
            System.out.println(inMessage3);
            
            output.println(scanner.next());
            
            String inMessage4 = input.readLine();
            System.out.println(inMessage4);
            inMessage4 = input.readLine();
            System.out.println(inMessage4);

            
        } catch (IOException e) {
            System.err.println("Error during communication!");
        }
        }
        
    }

    /** 
     * The main application method 
     * @param args
     * @throws java.net.UnknownHostException
     */
    public static void main(String[] args) throws IOException {
        int id = 1;
        RollOfDiceTCPClient rollOfDiceTCPClient = new RollOfDiceTCPClient(id, InetAddress.getByName(args[0]), Integer.parseInt(args[1]));
        rollOfDiceTCPClient.start();

    }
    
}
