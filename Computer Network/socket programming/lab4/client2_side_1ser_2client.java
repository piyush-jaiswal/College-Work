import java.net.*;
import java.io.*;

public class client2_side_1ser_2client
{
    public static void main(String args[])
    {
        try
        {
            //Creating client socket
            InetAddress address = InetAddress.getByName("172.19.2.68");
            Socket socketvar = new Socket(address, 1122);

            //Getting the input and output streams
            OutputStream outvar = socketvar.getOutputStream();
            DataOutputStream dataoutvar = new DataOutputStream(outvar);
            InputStream invar = socketvar.getInputStream();
            DataInputStream datainvar = new DataInputStream(invar);

            String msg = "";
            while(true)
            {
                msg = datainvar.readUTF();
                System.out.println("Client1 says "+msg);

                System.out.println("Hello client2, enter the message");
                msg = System.console().readLine();
                dataoutvar.writeUTF(msg);

                if(msg.equals("end"))
                    break;
            }

            //Closing socket
            socketvar.close();
        }

        catch(UnknownHostException e)
        {
            System.out.println("Unknownhost exception");
        }

        catch(IOException e)
        {
            System.out.println("IO Exception: "+e );
        }
    }
}