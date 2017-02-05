import java.net.*;
import java.io.*;

public class client1_side_1ser_2client
{
	public static void main(String args[])
	{
		try
		{
			//Creating client socket
			InetAddress address = InetAddress.getByName("172.19.21.135");
			Socket socketvar = new Socket(address, 8069);
			
			OutputStream outvar = socketvar.getOutputStream();
			DataOutputStream dataoutvar = new DataOutputStream(outvar);
			InputStream invar = socketvar.getInputStream();
			DataInputStream datainvar = new DataInputStream(invar);

			String message="";
			
			while(true)
			{
				//Getting message from client user
				System.out.println("Hello client1, enter the message");
				message = System.console().readLine();

				//Sending data to server
				dataoutvar.writeUTF(message);
				
				if(message.equals("end"))
					break;

				//Receive data from server
				System.out.println("Client2 says " + datainvar.readUTF());
			}
			
			//Closing socket
			socketvar.close();
		}

		catch(UnknownHostException e) // Catching unknown host exception
		{
			System.out.println("Unknownhost exception");
		}

		catch(IOException e) // Catching IOException
		{
			System.err.println("IOException : "+e);
		}
	}
}
