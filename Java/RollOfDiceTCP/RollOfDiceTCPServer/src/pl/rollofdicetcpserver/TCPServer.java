package pl.rollofdicetcpserver;

import java.net.*;
import java.io.*;
import pl.model.DiceException;
import pl.model.Model;

/**
 * The main class of the server
 *
 * @author Szymon Szpakowski
 * @version 3.1
 */
public class TCPServer implements Closeable {

    /**
     * port number
     */
    private int PORT;

    /**
     * field represents the socket waiting for client connections
     */
    private ServerSocket serverSocket;
    
 

    /**
     * Creates the server socket
     *
     * @throws IOException when prot is already bind
     */
    TCPServer(Integer port) throws IOException {
        this.PORT = port;
        serverSocket = new ServerSocket(PORT);
    }

    
    /**
     * The main application method
     * @param args first argument is port
     */
    public static void main(String args[]) {
        Model modelm = new Model();
        int serverPort = 8889;
        try {
                serverPort = Integer.parseInt(args[0]);
            }catch (NumberFormatException ex) {
                System.out.println("No numbers of type int!!! Argument should be of type int!");
            }
       
            

        try (TCPServer tcpServer = new TCPServer(serverPort)) {
            System.out.println("Server started");
            while (true) {
                Socket socket = tcpServer.serverSocket.accept();
                try (SingleService singleService = new SingleService(socket, modelm)) {
                    singleService.realize();
                } catch (IOException e) {
                    System.err.println(e.getMessage());
                }
            }
        } catch (IOException e) {
            System.err.println(e.getMessage());
        }
    }

    /**
     * closing
     * @throws IOException communication
     */
    @Override
    public void close() throws IOException {
        if (serverSocket != null) {
            serverSocket.close();
        }
    }
}


/**
 * The server class servicing a single connection
 * Communication with client
 * @author Szymon Szpakowski
 */
class SingleService implements Closeable {

    /**
     * socket representing connection to the client
     */
    private Socket socket;
    /**
     * buffered input character stream
     */
    private BufferedReader input;
    /**
     * Formatted output character stream
     */
    private PrintWriter output;
    
    /**model field to act on model*/
    private Model model;

    /**
     * if false waiting for number of dices
     */
    boolean arg1 = false;
    /**
     * if true waiting for number of walls
     */
    boolean arg2 = false;
    /**
     * if true waiting for mode
     */
    boolean arg3 = false;
    /**
     * if true waiting calculates result
     */
    boolean allArgs = false;

    /**
     * The constructor of instance of the SingleService class. Use the socket as
     * a parameter.
     *
     * @param socket socket representing connection to the client
     */
    public SingleService(Socket socket, Model model) throws IOException {
        this.socket = socket;
        this.model = model;
        output = new PrintWriter(
                new BufferedWriter(
                        new OutputStreamWriter(
                                socket.getOutputStream())), true);
        input = new BufferedReader(
                new InputStreamReader(
                        socket.getInputStream()));
    }

    /**
     * Realizes the service
     * Communicate with client and
     * sets fields of model which should be passed by user.
     * verifies arguments and set them in model.
     * 
     */
    public void realize() {
        try {
            output.println("Welcome to Roll Of Dice Java Sever");
            output.println("If you want to play enter number of dices(1 or more),"
                    + " number of walls(4 or more) and  mode('sum' or 'max'). "
                    + "QUIT to close. HELP to show how to enter arguments");
            output.println("First enter number of dices: ");

            while (true) {
                String str;
                if(this.arg1 == false){
                    try{
                        str = input.readLine();
                        System.out.println("Client sent: " + str);
                        if (str.toUpperCase().equals("QUIT")) {
                            break;
                        }
                        if (str.toUpperCase().equals("HELP")) {
                            output.println("Type number of dices(1 or more) and click enter button on your keyboard,"
                                    + " then type number of walls(4 or more) and click enter button"
                                    + "then type mode('sum' or 'max') and click enter button");
                            continue;
                        }
                        model.setNumOfDices(Integer.parseInt(str));
                        output.println("Number of dices saved on server.");
                        this.arg1 = true;
                        this.arg2 = true;
                        output.println("Enter number of walls: ");
                    } catch (NumberFormatException ex) {
                        output.println("No numbers of type int!!! Number of dices should be of type int! Enter number of dices again or QUIT to close!");
                        this.arg1 = false;
                        this.arg2 = false;
                    }   
                }
                
                if(this.arg2 == true){
                    try{
                        str = input.readLine();
                        System.out.println("Client sent: " + str);
                        if (str.toUpperCase().equals("QUIT")) {
                            break;
                        }
                        if (str.toUpperCase().equals("HELP")) {
                            output.println("Type number of walls(4 or more) and click enter button on your keyboard"
                                    + "then type mode('sum' or 'max') and click enter button");
                            continue;
                        }
                        model.setNumOfWalls(Integer.parseInt(str));
                        output.println("Number of walls saved on server.");
                        this.arg2 = false;
                        this.arg3 = true;
                        output.println("Enter mode: ");
                    } catch (NumberFormatException ex) {
                        output.println("No numbers of type int!!! Number of walls should be of type int! Enter number of walls again or QUIT to close!");
                        this.arg3 = false;
                        this.arg2 = true;
                    } 
                }
                
                if(this.arg3 == true){
                    str = input.readLine();
                    System.out.println("Client sent: " + str);
                    if (str.toUpperCase().equals("QUIT")) {
                            break;
                        }
                    if (str.toUpperCase().equals("HELP")) {
                            output.println("Type mode('sum' or 'max') and click enter button on your keyboard");
                            continue;
                        }
                     if (!str.equals("sum") && !str.equals("max")){
                         output.println("Wrong throw mode!!! Mode should be 'max' or 'sum'! Enter mode again or QUIT to close!");
                     }
                     else{
                        model.setMode(str);
                        output.println("Mode saved on server.");
                        this.arg3 = false;
                        this.allArgs = true;
                        this.throwDices();
                     }
                    } 
                
                if(this.allArgs == true){
                    
                    
                    output.println("If you want to start again type RESTART(and then number of dices), "
                            + "if not type QUIT to close.");
                    str = input.readLine();
                    System.out.println("Client sent: " + str);
                    if (str.toUpperCase().equals("QUIT")) {
                            break;
                        }
                    if (str.toUpperCase().equals("RESTART")) {
                            this.arg1=false;
                            this.arg2=false;
                            this.arg3=false;
                            this.allArgs=false;
                        }
                }

            }
            System.out.println("closing...");
        } catch (IOException e) {
            System.err.println(e.getMessage());
        } finally {
            try {
                socket.close();
            } catch (IOException e) {
                System.err.println(e.getMessage());
            }
        }
    }
    
    /**
     * method starts(if no errors occured) logic from model
     * uses my own exception implemented in model
     */
    public void throwDices() {
        
        try {
                model.throwDices();
                if(model.getMode().equals("max"))
                    output.println("Max number of your rolls is: " + model.getResult());
                else
                    output.println("Sum of your rolls is: " + model.getResult());
            } catch (DiceException ex) {
                output.println(ex.getMessage());
            }
    }

    @Override
    public void close() throws IOException {
        if (socket != null) {
            socket.close();
        }
    }
}
