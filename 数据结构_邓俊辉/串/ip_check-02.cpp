#include <string.h>

/**
 * 验证IP地址
 * @param IP string字符串 一个IP地址字符串
 * @return string字符串
 */
int check_ip_as_ipv4(char *ip,int len)
{
    int i = 0,val =0,nodeLen =0,nodeNum =0;
    if(len > 15 || len < 7)
    {
        return -1;
    }
    while(i < len)
    {
        if(ip[i] == '.')
        {
            if(i == 0 || ip[i-1]=='.')
                return -1;
            if(val > 255 || val < 0)
            {
                return -2;
            }
            if(val == 0 && nodeLen > 1)
            {
                return -3;
            }
            val = 0;
            nodeLen = 0;
            nodeNum ++;
            if(nodeNum > 4)
                return -4;
            i++;
        }
        else if(ip[i] < '0' || ip[i] > '9')
            return -5;
        if(val == 0 && nodeLen >= 1)
        {
            return -6;
        }
        val = val*10 +(ip[i]-'0');
        nodeLen ++;
        i++;
    }
    return 0;
}
int check_ip_as_ipv6(char *ip,int len)
{
    int i = 0,val =0,nodeLen =0,nodeNum =0,tmpVal = 0;
    if(len > 39 || len < 15)
    {
        return -1;
    }
    while(i < len)
    {
        if(ip[i] == ':')
        {
            if(i == 0 || ip[i-1]==':')
                return -1;
            if(nodeLen > 4)
            {
                return -2;
            }
            if(val ==0 && nodeLen ==4)
                return -3;
            val = 0;
            nodeLen = 0;
            nodeNum ++;
            if(nodeNum > 8)
                return -4;
            i++;
        }
        else if((ip[i] >= '0' && ip[i] <= '9'))
        {
            tmpVal = ip[i]-'0';
        }
        else if(ip[i] >= 'a' && ip[i] <= 'f')
        {
            tmpVal = ip[i]-'a'+10;
        }
        else if(ip[i] >= 'A' && ip[i] <= 'F')
        {
            tmpVal = ip[i]-'A'+10;
        }
        else
        {
            return -6;
        }
        val = val*16 + tmpVal;
        nodeLen ++;
        i++;
    }
    return 0;
}
char* solve(char* IP ) {
    // write code here
    int len = 0,i=0,ret =0;
    if(NULL == IP)
    {
        return NULL;
    }
    len = strlen(IP);
    while(i<len){
        if(IP[i]=='.'){
            ret = check_ip_as_ipv4(IP,len);
            if(0 == ret){
                return "IPv4";}
            break;
        }
        else if(IP[i]==':'){
            ret = check_ip_as_ipv6(IP,len);
            if(0 == ret)
                return "IPv6";
            break;
        }
        i++;
    }
    return "Neither";
}