import java.net.*;
import java.io.*;

public class server_side
{
	public static void main(String args[])
	{
		try
		{
			//Creating server socket
			ServerSocket ssvar = new ServerSocket(1563);
			Socket server = ssvar.accept();

			//Receive data from client
			InputStream invar = server.getInputStream();
			DataInputStream datainvar = new DataInputStream(invar);
			System.out.println("Client says " + datainvar.readUTF());

			//Send data to client
			OutputStream outvar = server.getOutputStream();
			DataOutputStream dataoutvar = new DataOutputStream(outvar);
			dataoutvar.writeUTF("Hello from server");

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
