import java.net.*;
import java.io.*;

public class ser_side_1ser_2client
{
    public static void main(String args[])
    {
        try
        {
            ServerSocket ssvar = new ServerSocket(1122);
            Socket socket1 = ssvar.accept();
            Socket socket2 = ssvar.accept();

            //Setting the input streams
            InputStream invar1 = socket1.getInputStream();
            DataInputStream datainvar1 = new DataInputStream(invar1);
            InputStream invar2 = socket2.getInputStream();
            DataInputStream datainvar2 = new DataInputStream(invar2);

            //Setting the output streams
            OutputStream outvar1 = socket1.getOutputStream();
            DataOutputStream dataoutvar1 = new DataOutputStream(outvar1);
            OutputStream outvar2 = socket2.getOutputStream();
            DataOutputStream dataoutvar2 = new DataOutputStream(outvar2);

            String msg = "";
            while(true)
            {
                //Reading from client1 and sending to client2
                msg = datainvar1.readUTF();
                dataoutvar2.writeUTF(msg);
                if(msg.equals("end"))
                    break;

                //Reading from client2 and sending to client1
                msg = datainvar2.readUTF();
                dataoutvar1.writeUTF(msg);
                if(msg.equals("end"))
                    break;

            }

            socket1.close();
            socket2.close();
        }

        catch(UnknownHostException e)
        {
            System.out.println("Unknownhost exception");
        }

        catch(IOException e)
        {
            System.out.println("IOException: "+e.getMessage());
        }
    }
}