import java.net.*;
import java.io.*;

public class test_server
{
    public static void main(String args[])
    {
        try
        {
            ServerSocket ssvar = new ServerSocket(1630);
            Socket server = ssvar.accept();

            InputStream invar = server.getInputStream();
            DataInputStream datainvar = new DataInputStream(invar);
            OutputStream outvar = server.getOutputStream();
            DataOutputStream dataoutvar = new DataOutputStream(outvar);

            String msg="";

            while(true)
            {
                msg = datainvar.readUTF();
                System.out.println("Client says: "+msg);
                if(msg.equals("end"))
                    break;

                System.out.println("Hello server, enter message");
                msg = System.console().readLine();
                dataoutvar.writeUTF(msg);

                ssvar.close();
            }
        }

        catch(UnknownHostException e)
        {
            System.out.println("Unknownhost exception: " + e.getMessage());
        }

        catch(IOException e)
        {
            System.out.println("IO exception: " + e.getMessage());
        }
    }
}