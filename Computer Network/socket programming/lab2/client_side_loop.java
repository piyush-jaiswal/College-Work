import java.net.*;
import java.io.*;

public class client_side_loop
{
	public static void main(String args[])
	{
		try
		{
			//Creating client socket
			Socket socketvar = new Socket("localhost", 1563);

			//Getting message from client
			System.out.println("Hello client, enter the message");
			String message = System.console().readLine();

			//Sending data to server 10 times
			for(int i=0; i<10; i++)
			{
				OutputStream outvar = socketvar.getOutputStream();
				DataOutputStream dataoutvar = new DataOutputStream(outvar);
				dataoutvar.writeUTF(message);

			//Receive data from server 10 times

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
			System.err.println(e);
		}
	}
}
