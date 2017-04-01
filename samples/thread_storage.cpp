#include <pthread.h>

pthread_key_t _tls;
void destruction(void* data)
{
    printf("destruction called\n");
}

int main(int argc, char** argv)
{
    pthread_key_create(&_tls, destruction);
    pthread_setspecific(_tls, new char[20]);
    char* temp = static_cast<char*> (pthread_getspecific(_tls));
    sprintf(temp, "hello, wold!");
    char* temp2 = static_cast<char*> (pthread_getspecific(_tls));
    printf("temp2 = %s\n", temp2);
    pthread_setspecific(_tls, 0);
    
    pthread_key_destroy(&_tls);

}