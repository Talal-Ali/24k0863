int romanToInt(char* s) {
    int x=0;
    int slen = strlen(s);
    
    for(int i=0; i<slen; i++)
    {
        switch(s[i])
        {
            case 'I':
                    if((s[i+1]=='V' || s[i+1] == 'X')&& i+1<slen)
                    {
                        x--;
                    }
                    else
                    {
                        x++;
                    }break;
                    
            case 'V': 
                    x+=5;
                    break;
            case 'X': if((s[i+1] == 'L' || s[i+1] == 'C')&& i+1<slen)
                        {
                            x-=10;
                        }
                        else
                        {
                            x+=10;
                        }break;
            case 'L': 
                        x+=50;
                        break;
            case 'C': if(i+1<slen && (s[i+1] == 'M' || s[i+1] == 'D'))
                        {
                            x-=100;
                        }
                        else
                        {
                            x+=100;
                        }
                        break;
            case 'D': 
                        x+=500;
                        break;
            case 'M':
                        x+=1000;
                        break;
            default: continue;
        }
        
    }
    return x;
}

int main()
{
	char str[] = "XXIV";
	romanToInt(str);
}