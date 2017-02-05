import java.net.*;
import java.io.*;

public class client_side_end
{
	public static void main(String args[])
	{
		try
		{
			//Creating client socket
			Socket socketvar = new Socket("localhost", 1563);
			
			String message="";
			
			while(true)
			{
			//Getting message from client user
				System.out.println("Hello client, enter the message");
				message = System.console().readLine();

			//Sending data to server
				OutputStream outvar = socketvar.getOutputStream();
				DataOutputStream dataoutvar = new DataOutputStream(outvar);
				dataoutvar.writeUTF(message);
				
				if(message.equals("end"))
					break;

			//Receive data from server
				InputStream invar = socketvar.getInputStream();
				DataInputStream datainvar = new DataInputStream(invar);
				System.out.println("Server says " + datainvar.readUTF());
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
