import java.net.*;
import java.io.*;

public class server_side_end
{
	public static void main(String args[])
	{
		try
		{
			//Creating server socket
			ServerSocket ssvar = new ServerSocket(1563);
			Socket server = ssvar.accept();

			String client_message="";

			while(true)
			{
				
			//Receive data from client
				InputStream invar = server.getInputStream();
				DataInputStream datainvar = new DataInputStream(invar);
				client_message = datainvar.readUTF();
				System.out.println("Client says " + client_message);
				
				if(client_message.equals("end"))
					break;
				
			//Receive message from server user
				System.out.println("Hello server, enter the message");
				String message = System.console().readLine();

			//Send data to client
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
