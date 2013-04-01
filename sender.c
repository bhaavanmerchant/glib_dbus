#include<glib.h>
#include<dbus/dbus-glib.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main (int argc, char **argv)
{
  DBusGConnection *connection;
  GError *error;
  DBusGProxy *proxy;
  char **name_list;
  char **name_list_ptr;
  
  g_type_init ();

  error = NULL;
  connection = dbus_g_bus_get (DBUS_BUS_SESSION,
                               &error);
  if (connection == NULL)
    {
      g_printerr ("Failed to open connection to bus: %s\n",
                  error->message);
      g_error_free (error);
      exit (1);
    }

//   Create a proxy object for the "bus driver" (name "org.freedesktop.DBus") 
  
    proxy = dbus_g_proxy_new_for_name (connection,
                                     "org.gnome.Transfers",
                                     DBUS_PATH_DBUS,
                                     DBUS_INTERFACE_DBUS);

//   Call ListNames method, wait for reply 
  error = NULL;
  GArray *arr;
  if (!dbus_g_proxy_call (proxy, "Foobar", &error,
                          G_TYPE_INT, 42, G_TYPE_STRING, "hello", G_TYPE_INVALID, 
                            DBUS_TYPE_G_UCHAR_ARRAY, &arr, G_TYPE_INVALID))
    {
//       Just do demonstrate remote exceptions versus regular GError 
      if (error->domain == DBUS_GERROR && error->code == DBUS_GERROR_REMOTE_EXCEPTION)
        g_printerr ("Caught remote method exception %s: %s",
	            dbus_g_error_get_name (error),
	            error->message);
      else
        g_printerr ("Error: %s\n", error->message);
      g_error_free (error);
      exit (1);
    }

//   Print the results 
 
  g_print("Something sent\n");

  g_object_unref (proxy);

  return 0;
}
