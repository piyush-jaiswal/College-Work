import java.net.*;
import java.io.*;

public class client_side
{
	public static void main(String args[])
	{
		try
		{
			//Creating client socket
			Socket socketvar = new Socket("localhost", 1563);

			//Sending data to server
			OutputStream outvar = socketvar.getOutputStream();
			DataOutputStream dataoutvar = new DataOutputStream(outvar);
			dataoutvar.writeUTF("Hello from client");

			//Receive data from server
			InputStream invar = socketvar.getInputStream();
			DataInputStream datainvar = new DataInputStream(invar);
			System.out.println("Server says " + datainvar.readUTF());
			
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
