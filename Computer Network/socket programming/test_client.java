import java.net.*;
import java.io.*;

public class test_client
{
    public static void main(String args[])
    {
        try
        {
            Socket client = new Socket("localhost", 1630);

            InputStream invar = client.getInputStream();
            DataInputStream datainvar = new DataInputStream(invar);
            OutputStream outvar = client.getOutputStream();
            DataOutputStream dataoutvar = new DataOutputStream(outvar);

            String msg="";

            while(true)
            {
                System.out.println("Hello client, enter message");
                msg = System.console().readLine();

                dataoutvar.writeUTF(msg);
                if(msg.equals("end"))
                    break;

                msg = datainvar.readUTF();
                System.out.println("Server says: "+msg);
            }

            client.close();
        }

        catch(UnknownHostException e)
        {
            System.out.println("UnknownHost Exception :"+ e.getMessage());
        }

        catch(IOException e)
        {
            System.out.println("IOException :"+ e.getMessage());
        }

    }
}