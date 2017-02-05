import java.net.*;
import java.io.*;

public class server_side_loop
{
	public static void main(String args[])
	{
		try
		{
			//Creating server socket
			ServerSocket ssvar = new ServerSocket(1563);
			Socket server = ssvar.accept();

			//Getting message from client
			System.out.println("Hello server, enter the message");
			String message = System.console().readLine();

			//Receive data from client 10 times
			for(int i=0; i<10; i++)
			{
				InputStream invar = server.getInputStream();
				DataInputStream datainvar = new DataInputStream(invar);
				System.out.println("Client says " + datainvar.readUTF());

			//Send data to client 10 times

				OutputStream outvar = server.getOutputStream();
				DataOutputStream dataoutvar = new DataOutputStream(outvar);
				dataoutvar.writeUTF(message);
			}

			//Closing Socket
			ssvar.close();
		}

		catch(UnknownHostException e) // Catching unknown host exception
		{
			System.out.println("Unknownhost exception");
		}

		catch(IOException e) // Catching IOException
		{
			System.out.println("IO Exception");
		}
	}
}
