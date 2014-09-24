#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAXBUFSIZE 1024


char* get_self_executable_directory ()
{
  int rval;
  char link_target[1024];//目标地址
  char* last_slash;
  size_t result_length;//结果的长度
  char* result;

  /* Read the target of the symbolic link /proc/self/exe.  */
  rval = readlink ("/proc/self/exe", link_target, sizeof (link_target) - 1);
  if (rval == -1)
    /* The call to readlink failed, so bail.  */
    abort ();
  else
    /* NUL-terminate the target.  */
    link_target[rval] = '\0';
  /* We want to trim the name of the executable file, to obtain the
     directory that contains it.  Find the rightmost slash.  */

  last_slash = strrchr (link_target, '/');
  if (last_slash == NULL || last_slash == link_target)
    /* Something stange is going on.  */
    abort ();
  /* Allocate a buffer to hold the resulting path.  */

  result_length = last_slash - link_target;
  result = (char*)malloc (result_length + 1);
  /* Copy the result.  */
  strncpy (result, link_target, result_length);
  result[result_length] = '\0';
  return result;
}




int main ( int argc, char * argv[] )
{
    char buf[ MAXBUFSIZE ];
    int  count;

    count = readlink( "/proc/self/exe", buf, MAXBUFSIZE );
    if ( count < 0 || count >= MAXBUFSIZE )
    {
        printf( "Failed\n" );
       return( EXIT_FAILURE );
    }
    buf[count] = '\0';
    printf( "/proc/self/exe -> [%s]\n", buf );
    return( EXIT_SUCCESS );
}  


