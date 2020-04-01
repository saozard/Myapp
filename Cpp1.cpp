#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
char getOpt()//运算符 
{
    char opt[4]={'+','-','x','/'};
    return opt[rand()%4];
}
int random(int a)//随机数 
{
	int b;
    b=rand()%a;
	return b;
}
int gcd(int x,int y)//辗转相除法 
{
    if(y==0) return x;
    return gcd(y,x%y);
}

int Answers1(int y,char str[],int r)//生成答案 
{
	int question(int y,int r);
	int a,c=0;
	FILE *fp;
	fp=fopen("Answers.txt","a");
	int ans1,ans2,num1,num2;
	char opt;
	num1=str[0]-48;
	num2=str[2]-48;
	opt=str[1];
	switch(opt)
	{
		case '+':
		    fprintf(fp,"答案%d：%d\n",y,num1+num2);
		    fclose(fp);break;
		case '-':
			if(num1<num2)
				return -1;
			else
			{
			    fprintf(fp,"答案%d：%d\n",y,num1-num2);
			    fclose(fp);break;
			}
		case 'x':
		    fprintf(fp,"答案%d：%d\n",y,num1*num2);
		    fclose(fp);break;
		case '/':
			a=gcd(num1,num2);
			ans1=num1/a;
			ans2=num2/a;
			c=0;
			while(ans1>=ans2)
			{
				ans1=ans1-ans2;
				c++;
			}
			if(c>0&&ans1!=0)
				fprintf(fp,"答案%d：%d'%d/%d\n",y,c,ans1,ans2);
			else if(c==0)
				fprintf(fp,"答案%d：%d/%d\n",y,ans1,ans2);
			else
				fprintf(fp,"答案%d：%d\n",y,c);
		    fclose(fp);break;
	}
	return 0;
}

int Answers2(int y,char str[],int r)//生成答案 
{
	int question(int y,int r);
	int ans,a,c=0;
	FILE *fp;
	fp=fopen("Answers.txt","a");
	int num1,num2,num3;
	char opt1,opt2;
	num1=str[0]-48;
	opt1=str[1];
	num2=str[2]-48;
	opt2=str[3];
	num3=str[4]-48;
	if(opt2=='x'&&opt1!='/')
	{
		int ans1;
		ans1=num2*num3;
		switch(opt1)
		{
		    case '+':
		    	ans=num1+ans1;
		   	    fprintf(fp,"答案%d：%d\n",y,ans);
	    	    fclose(fp);break;
		   	case '-':
	    		if(num1<ans1)
					return -1;
	    		else
	    		{
				    ans=num1-ans1;
	    		    fprintf(fp,"答案%d：%d\n",y,ans);
	    	        fclose(fp);
				}break;
		   	case 'x':
	    		ans=num1*ans1;
	    	    fprintf(fp,"答案%d：%d\n",y,ans);
	    	    fclose(fp);break;
	    }
	}
	else if(opt2=='/'&&opt1!='/')
		{
			int ans1,ans2;
			c=0;
			a=gcd(num2,num3);
			ans1=num2/a;
			ans2=num3/a;
			while(ans1>=ans2)
			{
				ans1=ans1-ans2;
				c++;
			}
			switch(opt1)
		    {
		    	case '+':
		    		c=num1+c;
					if(ans1!=0&&c!=0)
		    			fprintf(fp,"答案%d：%d'%d/%d\n",y,c,ans1,ans2);
					else if(ans1==0)
						fprintf(fp,"答案%d：%d\n",y,c);
					else
		    			fprintf(fp,"答案%d：%d/%d\n",y,ans1,ans2);
		    	    fclose(fp);break;
		    	case '-':
		    		if(num1<=c)
						return -1;
		    		else
		    		{
		    	    	c=num1-c;
		        		int a1,a2;
		        		if(c=1)
		        		{
		        			a1=ans2-ans1;
		        			a2=ans2;
		    			}
		    			else
		    			{
		    				c--;
			    			a1=ans2-ans1;
		        			a2=ans2;
		    			}
		        	}
					if(ans1!=0&&c!=0)
		    			fprintf(fp,"答案%d：%d'%d/%d\n",y,c,ans1,ans2);
					else if(ans1==0)
						fprintf(fp,"答案%d：%d\n",y,c);
					else
		    			fprintf(fp,"答案%d：%d/%d\n",y,ans1,ans2);
		    	    fclose(fp);break;
		    	case 'x':
		    		int ans1;
		    		c=0;
					ans1=num1*num2;
		    		a=gcd(ans1,num3);
		    		ans1=ans1/a;
		    		ans2=num3/a;
		    		while(ans1>=ans2)
		    		{
		    			ans1=ans1-ans2;
		    			c++;
					}
					if(ans1!=0&&c!=0)
		    			fprintf(fp,"答案%d：%d'%d/%d\n",y,c,ans1,ans2);
					else if(ans1==0)
						fprintf(fp,"答案%d：%d\n",y,c);
					else
		    			fprintf(fp,"答案%d：%d/%d\n",y,ans1,ans2);
		    	    fclose(fp);break;
		    }
		}
	    if(opt1=='/')
	    {
	    	int ans1,ans2;
	    	c=0;
	    	switch(opt2)
	    	{
	    		case '+':
	    			a=gcd(num1,num2);
	    			ans1=num1/a;
	    			ans2=num2/a;
	    			c=0;
	    			while(ans1>=ans2)
	    			{
	    				ans1=ans1-ans2;
	    				c++;
					}
					c=c+num3;
					if(ans1!=0&&c!=0)
		    			fprintf(fp,"答案%d：%d'%d/%d\n",y,c,ans1,ans2);
					else if(ans1==0)
						fprintf(fp,"答案%d：%d\n",y,c);
					else
		    			fprintf(fp,"答案%d：%d/%d\n",y,ans1,ans2);
					fclose(fp);break;
				case '-':
					a=gcd(num1,num2);
	    			ans1=num1/a;
	    			ans2=num2/a;
	    			c=0;
	    			while(ans1>=ans2)
	    			{
	    				ans1=ans1-ans2;
	    				c++;
					}
					if(c<num3) return -1;
					else 
					if(c=num3)
					{
					if(ans1!=0&&c!=0)
		    			fprintf(fp,"答案%d：%d'%d/%d\n",y,c,ans1,ans2);
					else if(ans1==0)
						fprintf(fp,"答案%d：%d\n",y,c);
					else
		    			fprintf(fp,"答案%d：%d/%d\n",y,ans1,ans2);
						fclose(fp);
					}
					else
					if(c>num3)
					{
						c=c-num3;
					if(ans1!=0&&c!=0)
		    			fprintf(fp,"答案%d：%d'%d/%d\n",y,c,ans1,ans2);
					else if(ans1==0)
						fprintf(fp,"答案%d：%d\n",y,c);
					else
		    			fprintf(fp,"答案%d：%d/%d\n",y,ans1,ans2);
						fclose(fp);
					}break;
				case 'x':
					ans1=num1*num3;
					a=gcd(ans1,num2);
					ans1=ans1/a;
					ans2=num2/a;
					c=0;
					while(ans1>=ans2)
	    			{
	    				ans1=ans1-ans2;
	    				c++;
					}
					if(ans1!=0&&c!=0)
		    			fprintf(fp,"答案%d：%d'%d/%d\n",y,c,ans1,ans2);
					else if(ans1==0)
						fprintf(fp,"答案%d：%d\n",y,c);
					else
		    			fprintf(fp,"答案%d：%d/%d\n",y,ans1,ans2);
					fclose(fp);break;
				case '/':
					ans2=num2*num3;
					a=gcd(num1,ans2);
					ans1=num1/a;
					ans2=ans2/a;
					c=0;
					while(ans1>=ans2)
	    			{
	    				ans1=ans1-ans2;
	    				c++;
					}
					if(ans1!=0&&c!=0)
		    			fprintf(fp,"答案%d：%d'%d/%d\n",y,c,ans1,ans2);
					else if(ans1==0)
						fprintf(fp,"答案%d：%d\n",y,c);
					else
		    			fprintf(fp,"答案%d：%d/%d\n",y,ans1,ans2);
					fclose(fp);break;
			}
		}
		else
		if(opt1='+')
	    {
	    	int ans1,ans2;
	    	c=0;
	    	switch(opt2)
    		{
	    		case '+':
	    			ans=num1+num2+num3;
	    		    fprintf(fp,"答案%d：%d\n",y,ans);
	    		    fclose(fp);break;
    			case '-':
    				if((num1+num2)<num3)return -1;
    				else
    				{
    					ans=num1+num2-num3;
	    		        fprintf(fp,"答案%d：%d\n",y,ans);
	    		        fclose(fp);break;
					}
	    	}
	    }
	    else
	    if(opt1='-')
	    {
	    	switch(opt2)
    		{
	    		case '+':
	    			if((num1-num2+num3)<0)
						return -1;
	    			else
	    			{
	    				ans=num1-num2+num3;
	    		        fprintf(fp,"答案%d：%d\n",y,ans);
	    		        fclose(fp);break;
					}	
    			case '-':
    				if((num1-num2-num3)<0)
						return -1;
    				else
    				{
    					ans=num1-num2-num3;
	    		        fprintf(fp,"答案%d：%d\n",y,ans);
	    		        fclose(fp);break;
					}
	    	}
		}
		else
		if(opt1='x')
		{
			switch(opt2)
    		{
	    		case '+':
	    			ans=num1*num2+num3;
	    		    fprintf(fp,"答案%d：%d\n",y,ans);
	    		    fclose(fp);break;
    			case '-':
					ans=num1*num2;
    				if(ans<num3)
						return -1;
    				else
    				{
    					ans-=num3;
	    		        fprintf(fp,"答案%d：%d\n",y,ans);
	    		        fclose(fp);break;
					}
	    	}
		}
	return 0;
}

int Answers3(int y,char str[],int r)//生成答案 
{
	int question(int y,int r);
	int ans,a,c=0;
	FILE *fp;
	fp=fopen("Answers.txt","a");
	int num1,num2,num3,num4;
	char opt1,opt2,opt3;
	num1=str[0]-48;
	opt1=str[1];
	num2=str[2]-48;
	opt2=str[3];
	num3=str[4]-48;
	opt3=str[5];
	num4=str[6]-48;
	if(opt1=='x')
	{
		int ans1;
		ans1=num1*num2;
		if(opt3=='x'&&opt2!='/')
	    {
		    int ans2;
		   	ans2=num3*num4;
		   	switch(opt2)
			{
		       	case '+':
		       		ans=ans1+ans2;
		       	    fprintf(fp,"答案%d：%d\n",y,ans);
		       	    fclose(fp);break;
		       	case '-':
		       		if(ans1>=ans2)return -1;
		       		else
		       		{
		       			ans=ans1-ans2;
		       	        fprintf(fp,"答案%d：%d\n",y,ans);
		           	    fclose(fp);
				 	}break;
		       	case 'x':
	    	   		ans=ans1*ans2;
		       	    fprintf(fp,"答案%d：%d\n",y,ans);
		       	    fclose(fp);break;
		     }
		}
	   	else if(opt3=='/'&&opt2!='/')
	   	{
	      	int ans2,ans3;
	      	c=0;
	      	switch(opt2)
		    {
		       	case '+':
		        	a=gcd(num3,num4);
		        	ans2=num3/a;
		        	ans3=num4/a;
		        	c=0;
		        	while(ans2>=ans3)
		        	{
		        		ans2=ans2-ans3;
		        		c++;
					}
					c=c+ans1;
					if(ans1!=0&&c!=0)
		    			fprintf(fp,"答案%d：%d'%d/%d\n",y,c,ans2,ans3);
					else if(ans1==0)
						fprintf(fp,"答案%d：%d\n",y,c);
					else
		    			fprintf(fp,"答案%d：%d/%d\n",y,ans2,ans3);
		       	    fclose(fp);break;
		       	case '-':
		      		if(ans1<(num3/num4))return -1;
		       		else
		       		{
		       			a=gcd(num3,num4);
		       			ans2=num3/a;
		       			ans3=num4/a;
		       			c=0;
		       			while(ans2>=ans3)
		       			{
		       				ans2=ans2-ans3;
		        			c++;
						}
						c=ans1-c-1;
						ans2=ans3-ans2;
					if(ans1!=0&&c!=0)
		    			fprintf(fp,"答案%d：%d'%d/%d\n",y,c,ans2,ans3);
					else if(ans1==0)
						fprintf(fp,"答案%d：%d\n",y,c);
					else
		    			fprintf(fp,"答案%d：%d/%d\n",y,ans2,ans3);
		                fclose(fp);
					}break;
		        		
		       	case 'x':
	    	   		ans1=ans1*num3;
	    	   		a=gcd(ans1,num4);
	    	   		c=0;
	    	   		ans2=ans1/a;
	    	   		ans3=num4/a;
	    	   		while(ans2>=ans3)
	    	   		{
	    	   			ans2=ans2-ans3;
	    	   			c++;
					}
					if(ans1!=0&&c!=0)
		    			fprintf(fp,"答案%d：%d'%d/%d\n",y,c,ans2,ans3);
					else if(ans1==0)
						fprintf(fp,"答案%d：%d\n",y,c);
					else
		    			fprintf(fp,"答案%d：%d/%d\n",y,ans2,ans3);
		       	    fclose(fp);break;
		      }
		}
		else if(opt2=='/')
		{
			c=0;
			int ans2;
			a=gcd(ans1,num3);
			ans1=ans1/a;
			ans2=num3/a;
			while(ans1>=ans2)
			{
				ans1=ans1-ans2;
				c++;
			}
			switch(opt3)
			{
				case '+':
					c=c+num4;
					if(ans1!=0&&c!=0)
		    			fprintf(fp,"答案%d：%d'%d/%d\n",y,c,ans1,ans2);
					else if(ans1==0)
						fprintf(fp,"答案%d：%d\n",y,c);
					else
		    			fprintf(fp,"答案%d：%d/%d\n",y,ans1,ans2);
				    fclose(fp);break;
				case '-':
					if(c<num4)
						return -1;
					else
					{
						c=c-num4;
					if(ans1!=0&&c!=0)
		    			fprintf(fp,"答案%d：%d'%d/%d\n",y,c,ans1,ans2);
					else if(ans1==0)
						fprintf(fp,"答案%d：%d\n",y,c);
					else
		    			fprintf(fp,"答案%d：%d/%d\n",y,ans1,ans2);
				        fclose(fp);
					}break;
				case 'x':
					ans1=num1*num2*num4;
					a=gcd(ans1,num3);
					c=0;
					ans1=ans1/a;
					ans2=num3/a;
					while(ans1>=ans2)
					{
						ans1=ans1-ans2;
						c++;
					}
					if(ans1!=0&&c!=0)
		    			fprintf(fp,"答案%d：%d'%d/%d\n",y,c,ans1,ans2);
					else if(ans1==0)
						fprintf(fp,"答案%d：%d\n",y,c);
					else
		    			fprintf(fp,"答案%d：%d/%d\n",y,ans1,ans2);
				    fclose(fp);break;
				case '/':
					ans2=num3*num4;
					a=gcd(ans1,ans2);
					c=0;
					ans1=ans1/a;
					ans2=ans2/a;
					while(ans1>=ans2)
					{
						ans1=ans1-ans2;
						c++;
					}
					if(ans1!=0&&c!=0)
		    			fprintf(fp,"答案%d：%d'%d/%d\n",y,c,ans1,ans2);
					else if(ans1==0)
						fprintf(fp,"答案%d：%d\n",y,c);
					else
		    			fprintf(fp,"答案%d：%d/%d\n",y,ans1,ans2);
					fclose(fp);break;
			}
		}
		else if(opt2=='x')
		{
			c=0;
			int ans2,ans;
			ans1=num1*num2*num3;
			switch(opt3)
			{
				case '+':
					ans=ans1+num4;
					fprintf(fp,"答案%d：%d\n",y,ans);
					fclose(fp);break;
				case '-':
					if(ans1<num4)
						return -1;
					else
					{
						ans=ans1-num4;
						fprintf(fp,"答案%d：%d\n",y,ans);
						fclose(fp);
					}break;
				case 'x':
					ans=ans1*num4;
					fprintf(fp,"答案%d：%d\n",y,ans);
					fclose(fp);break;
				case '/':
					a=gcd(ans1,num4);
					ans1=ans1/a;
					ans2=num4/a;
					while(ans1>=ans2)
					{
						ans1=ans1-ans2;
						c++;
					}
					if(ans1!=0&&c!=0)
		    			fprintf(fp,"答案%d：%d'%d/%d\n",y,c,ans1,ans2);
					else if(ans1==0)
						fprintf(fp,"答案%d：%d\n",y,c);
					else
		    			fprintf(fp,"答案%d：%d/%d\n",y,ans1,ans2);
					fclose(fp);break;
			}
		}
		else
	    {
		   	int ans2;
		   	switch(opt2)
    	   	{
	       		case '+':
	       			ans2=ans1+num3;break;
       			case '-':
	       			ans2=ans1-num3;break;
	       		case 'x':
       				ans2=ans1*num3;break;
	       	}
		    switch(opt3)
        	{
	       		case '+':
	       			ans=ans2+num4;
	       		    fprintf(fp,"答案%d：%d\n",y,ans);
	       		    fclose(fp);break;
        		case '-':
        			if(ans2<num4)return -1;
        			else
        			{
        				ans=ans2-num4;
	       		        fprintf(fp,"答案%d：%d\n",y,ans);
	       		        fclose(fp);
					}break;
	       	}
		}
   	}
	else if(opt1=='/')
	{
		c=0;
		int ans1,ans2,ans3;
		switch(opt2)
		{
			case '+':
				a=gcd(num1,num2);
				ans1=num1/a;
				ans2=num2/a;
				c=0;
				while(ans1>=ans2)
				{
					ans1=ans1-ans2;
					c++;
				}
				switch(opt3)
				{
					case '+':
						ans3=num3+num4;
						c=c+ans3;
					if(ans1!=0&&c!=0)
		    			fprintf(fp,"答案%d：%d'%d/%d\n",y,c,ans1,ans2);
					else if(ans1==0)
						fprintf(fp,"答案%d：%d\n",y,c);
					else
		    			fprintf(fp,"答案%d：%d/%d\n",y,ans1,ans2);
	       		        fclose(fp);break;
	       		    case '-':
	       		    	ans3=num3-num4;
	       		    	if(ans<0&&c+ans3<0)return -1;
	       		    	else
	       		    	{
	       		    		c=c+ans3;
					if(ans1!=0&&c!=0)
		    			fprintf(fp,"答案%d：%d'%d/%d\n",y,c,ans1,ans2);
					else if(ans1==0)
						fprintf(fp,"答案%d：%d\n",y,c);
					else
		    			fprintf(fp,"答案%d：%d/%d\n",y,ans1,ans2);
	       		            fclose(fp);
						}break;
					case 'x':
						ans3=num3*num4;
						c=c+ans3;
					if(ans1!=0&&c!=0)
		    			fprintf(fp,"答案%d：%d'%d/%d\n",y,c,ans1,ans2);
					else if(ans1==0)
						fprintf(fp,"答案%d：%d\n",y,c);
					else
		    			fprintf(fp,"答案%d：%d/%d\n",y,ans1,ans2);
	        	        fclose(fp);break;
	        	    case '/':
	        	    	ans1=num1*num4+num3*num2;
	        	    	ans2=num2*num4;
	        	    	a=gcd(ans1,ans2);
	        	    	c=0;
	        	    	ans1=ans1/a;
	        	    	ans2=ans2/a;
	        	    	while(ans1>=ans2)
	        	    	{
	        	    		ans1=ans1-ans2;
	        	    		c++;
						}
					if(ans1!=0&&c!=0)
		    			fprintf(fp,"答案%d：%d'%d/%d\n",y,c,ans1,ans2);
					else if(ans1==0)
						fprintf(fp,"答案%d：%d\n",y,c);
					else
		    			fprintf(fp,"答案%d：%d/%d\n",y,ans1,ans2);
	        	        fclose(fp);break;
				}break;
				break;
			case '-':
				a=gcd(num1,num2);
				c=0;
				ans1=num1/a;
				ans2=num2/a;
				while(ans1>=ans2)
				{
					ans1=ans1-ans2;
					c++;
				}
				switch(opt3)
				{
					case '+':
						ans3=num3-num4;
						if(c<ans3)
							return -1;
						else
						{
							c=c-ans3;
					if(ans1!=0&&c!=0)
		    			fprintf(fp,"答案%d：%d'%d/%d\n",y,c,ans1,ans2);
					else if(ans1==0)
						fprintf(fp,"答案%d：%d\n",y,c);
					else
		    			fprintf(fp,"答案%d：%d/%d\n",y,ans1,ans2);
	       		            fclose(fp);
						}break;
	       		    case '-':
	       		    	ans3=num3+num4;
	       		    	if(c<ans3)return -1;
	       		    	else
	      		    	{
	        		   		c=c-ans3;
					if(ans1!=0&&c!=0)
		    			fprintf(fp,"答案%d：%d'%d/%d\n",y,c,ans1,ans2);
					else if(ans1==0)
						fprintf(fp,"答案%d：%d\n",y,c);
					else
		    			fprintf(fp,"答案%d：%d/%d\n",y,ans1,ans2);
	        		        fclose(fp);
						}break;
					case 'x':
						ans3=num3*num4;
						if(c<ans3)return -1;
						else
						{
							c=c-ans3;
					if(ans1!=0&&c!=0)
		    			fprintf(fp,"答案%d：%d'%d/%d\n",y,c,ans1,ans2);
					else if(ans1==0)
						fprintf(fp,"答案%d：%d\n",y,c);
					else
		    			fprintf(fp,"答案%d：%d/%d\n",y,ans1,ans2);
	        		        fclose(fp);
						}break;
					case '/':
	        		   	ans1=num1*num4-num3*num2;
	        		   	ans2=num2*num4;
	        		   	a=gcd(ans1,ans2);
	        		   	c=0;
	        		   	ans1=ans1/a;
	        		   	ans2=ans2/a;
	        		   	while(ans1>=ans2)
	        		   	{
	        		   		ans1=ans1-ans2;
	        		   		c++;
						}
						if(ans1<0)return -1;
						else
						{
					if(ans1!=0&&c!=0)
		    			fprintf(fp,"答案%d：%d'%d/%d\n",y,c,ans1,ans2);
					else if(ans1==0)
						fprintf(fp,"答案%d：%d\n",y,c);
					else
		    			fprintf(fp,"答案%d：%d/%d\n",y,ans1,ans2);
	        		        fclose(fp);
						}break;
				}break;
				 break;
			case 'x':
				ans1=num1*num3;
				a=gcd(ans1,num2);
				ans1=ans1/a;
				ans2=num2/a;
				while(ans1>=ans2)
				{
					ans1=ans1-ans2;
					c++;
				}
				switch(opt3)
				{
					case '+':
						c=c+num4;
					if(ans1!=0&&c!=0)
		    			fprintf(fp,"答案%d：%d'%d/%d\n",y,c,ans1,ans2);
					else if(ans1==0)
						fprintf(fp,"答案%d：%d\n",y,c);
					else
		    			fprintf(fp,"答案%d：%d/%d\n",y,ans1,ans2);
	        	        fclose(fp);break;
	        	    case '-':
	        	    	if(c<num4)return -1;
	        	    	else
	        		   	{
	        		   		c=c-num4;
					if(ans1!=0&&c!=0)
		    			fprintf(fp,"答案%d：%d'%d/%d\n",y,c,ans1,ans2);
					else if(ans1==0)
						fprintf(fp,"答案%d：%d\n",y,c);
					else
		    			fprintf(fp,"答案%d：%d/%d\n",y,ans1,ans2);
	        	            fclose(fp);
						}break;
					case 'x':
						ans1=num1*num3*num4;
						a=gcd(ans1,num2);
						ans1=ans1/a;
						ans2=num2/a;
						c=0;
						while(ans1>=ans2)
						{
							ans1=ans1-ans2;
							c++;
						}
					if(ans1!=0&&c!=0)
		    			fprintf(fp,"答案%d：%d'%d/%d\n",y,c,ans1,ans2);
					else if(ans1==0)
						fprintf(fp,"答案%d：%d\n",y,c);
					else
		    			fprintf(fp,"答案%d：%d/%d\n",y,ans1,ans2);
	        		    fclose(fp);break;
	        	    case '/':
	        	    	ans1=num1*num3;
	        		   	ans2=num2*num4;
	        		   	c=0;
	        		   	a=gcd(ans1,ans2);
	        		   	ans1=ans1/a;
	        		   	ans2=ans2/a;
	        		   	while(ans1>=ans2)
						{
							ans1=ans1-ans2;
							c++;
						}
					if(ans1!=0&&c!=0)
		    			fprintf(fp,"答案%d：%d'%d/%d\n",y,c,ans1,ans2);
					else if(ans1==0)
						fprintf(fp,"答案%d：%d\n",y,c);
					else
		    			fprintf(fp,"答案%d：%d/%d\n",y,ans1,ans2);
	        		    fclose(fp);break;
				}break;
			    break;
			case '/':
				ans2=num2*num3;
				a=gcd(num1,ans2);
				ans1=num1/a;
				ans2=ans2/a;
				c=0;
				while(ans1>=ans2)
				{
					ans1=ans1-ans2;
					c++;
				}
				switch(opt3)
				{
					case '+':
						c=c+num4;
					if(ans1!=0&&c!=0)
		    			fprintf(fp,"答案%d：%d'%d/%d\n",y,c,ans1,ans2);
					else if(ans1==0)
						fprintf(fp,"答案%d：%d\n",y,c);
					else
		    			fprintf(fp,"答案%d：%d/%d\n",y,ans1,ans2);
	       		        fclose(fp);break;
	       		    case '-':
	        	    	if(c<num4)return -1;
	       		    	else
	        	    	{
	        	    		c=c-num4;
					if(ans1!=0&&c!=0)
		    			fprintf(fp,"答案%d：%d'%d/%d\n",y,c,ans1,ans2);
					else if(ans1==0)
						fprintf(fp,"答案%d：%d\n",y,c);
					else
		    			fprintf(fp,"答案%d：%d/%d\n",y,ans1,ans2);
	        	            fclose(fp);
						}break;
					case 'x':
						ans1=num1*num4;
						ans2=num2*num3;
						c=0;
						a=gcd(ans1,ans2);
						ans1=ans1/a;
						ans2=ans2/a;
						while(ans1>=ans2)
						{
							ans1=ans1-ans2;
							c++;
						}
					if(ans1!=0&&c!=0)
		    			fprintf(fp,"答案%d：%d'%d/%d\n",y,c,ans1,ans2);
					else if(ans1==0)
						fprintf(fp,"答案%d：%d\n",y,c);
					else
		    			fprintf(fp,"答案%d：%d/%d\n",y,ans1,ans2);
	        	        fclose(fp);break;
	        	    case '/':
	        	    	ans1=num1;
	        	    	ans2=num2*num3*num4;
	        	    	c=0;
	        	    	a=gcd(num1,ans2);
	        	    	ans1=num1/a;
	        	    	ans2=ans2/a;
	        		  	while(ans1>=ans2)
						{
							ans1=ans1-ans2;
							c++;
						}
					if(ans1!=0&&c!=0)
		    			fprintf(fp,"答案%d：%d'%d/%d\n",y,c,ans1,ans2);
					else if(ans1==0)
						fprintf(fp,"答案%d：%d\n",y,c);
					else
		    			fprintf(fp,"答案%d：%d/%d\n",y,ans1,ans2);
	        	        fclose(fp);break;
				}break;
			     break;
		}
	}
	else if(opt2=='x')
	{
		int ans1;
		c=0;
		ans1=num2*num3;
		switch(opt1)
	   	{
		   	int ans2;
		   	case '+':
		   		switch(opt3)
		        {
		          	case '+':
		       	    	ans=num1+ans1+num4;
		           	    fprintf(fp,"答案%d:%d\n",y,ans);
		           	    fclose(fp);break;
		            	case '-':
		            		if(num1+ans1<num4)return -1;
		            		else
		            		{
		            			ans=num1+ans1-num4;
		            			fprintf(fp,"答案%d:%d\n",y,ans);
		                	    fclose(fp);
							}break;
		             	case 'x':
	    	    	    	ans=num1+num4*ans1;
		            	    fprintf(fp,"答案%d:%d\n",y,ans);
		             	    fclose(fp);break;
		        	    case '/':
		            		a=gcd(ans1,num4);
		            		c=0;
		            		ans1=ans1/a;
		            		ans2=num4/a;
		            		while(ans1>=ans2)
		            		{
		            			ans1=ans1-ans2;
		            			c++;
							}
							c=c+num1;
					if(ans1!=0&&c!=0)
		    			fprintf(fp,"答案%d：%d'%d/%d\n",y,c,ans1,ans2);
					else if(ans1==0)
						fprintf(fp,"答案%d：%d\n",y,c);
					else
		    			fprintf(fp,"答案%d：%d/%d\n",y,ans1,ans2);
	 	        	        fclose(fp);break;
		            }break;
		            break;
				case '-':
		        	switch(opt3)
		            {
		            	case '+':
		            		if((a+num4)<ans1)
								return -1;
		            		else
		            		{
		            			ans=num1-ans1+num4;
		            			fprintf(fp,"答案%d:%d\n",y,ans);
		            	        fclose(fp);
							}break;
		            	case '-':
		            		if(num1<(ans1+num4))
								return -1;
		            		else
		            		{
		            			ans=num1-ans1-num4;
		            			fprintf(fp,"答案%d:%d\n",y,ans);
		                	    fclose(fp);
							}break;
		             	case 'x':
		             		if(num1<(ans1*num4))
								return -1;
		             		else
		             		{
		             			ans=num1-num4*ans1;
		             			fprintf(fp,"答案%d:%d\n",y,ans);
		             	        fclose(fp);
							}break;
		        	    case '/':
		            		a=gcd(ans1,num4);
		            		c=0;
		            		ans1=ans1/a;
		            		ans2=num4/a;
		            		while(ans1>=ans2)
		            		{
		            			ans1=ans1-ans2;
		            			c++;
							}
							if(num1<=c)return -1;
							else
							{
								c=num1-c-1;
								ans1=ans2-ans1;
					if(ans1!=0&&c!=0)
		    			fprintf(fp,"答案%d：%d'%d/%d\n",y,c,ans1,ans2);
					else if(ans1==0)
						fprintf(fp,"答案%d：%d\n",y,c);
					else
		    			fprintf(fp,"答案%d：%d/%d\n",y,ans1,ans2);
	 	        	            fclose(fp);
							}break;
		            }break;
			    break;
			}
		}
		else
		if(opt2=='/')
		{
			int ans1,ans2;
			c=0;
			a=gcd(num2,num3);
			ans1=num2/a;
			ans2=num3/a;
			while(ans1>=ans2)
			{
				ans1=ans1-ans2;
				c++;
			}
			switch(opt1)
			{
				case'+':
					switch(opt3)
					{
						case '+':
							c=c+num1+num4;
					if(ans1!=0&&c!=0)
		    			fprintf(fp,"答案%d：%d'%d/%d\n",y,c,ans1,ans2);
					else if(ans1==0)
						fprintf(fp,"答案%d：%d\n",y,c);
					else
		    			fprintf(fp,"答案%d：%d/%d\n",y,ans1,ans2);
	        		        fclose(fp);break;
	        		    case '-':
	        		    	if((num1+c)<num4)return -1;
	        		    	else
	        		    	{
	        		    		c=c+num1-num4;
					if(ans1!=0&&c!=0)
		    			fprintf(fp,"答案%d：%d'%d/%d\n",y,c,ans1,ans2);
					else if(ans1==0)
						fprintf(fp,"答案%d：%d\n",y,c);
					else
		    			fprintf(fp,"答案%d：%d/%d\n",y,ans1,ans2);
	        		            fclose(fp);break;
							}
						case 'x':
							ans1=num2*num4;
							c=0;
							a=gcd(ans1,num3);
							ans1=ans1/a;
							ans2=ans2/a;
							while(ans1>=ans2)
							{
								ans1=ans1-ans2;
								c++;
							}
							c=c+num1;
					if(ans1!=0&&c!=0)
		    			fprintf(fp,"答案%d：%d'%d/%d\n",y,c,ans1,ans2);
					else if(ans1==0)
						fprintf(fp,"答案%d：%d\n",y,c);
					else
		    			fprintf(fp,"答案%d：%d/%d\n",y,ans1,ans2);
	        		        fclose(fp);break;
	        		    case '/':
	        		    	ans2=num3*num4;
	        		    	c=0;
	        		    	a=gcd(num2,ans2);
	        		    	ans1=num2/a;
	        		    	ans2=ans2/a;
	        		    	while(ans1>=ans2)
							{
								ans1=ans1-ans2;
								c++;
							}
							c=c+num1;
					if(ans1!=0&&c!=0)
		    			fprintf(fp,"答案%d：%d'%d/%d\n",y,c,ans1,ans2);
					else if(ans1==0)
						fprintf(fp,"答案%d：%d\n",y,c);
					else
		    			fprintf(fp,"答案%d：%d/%d\n",y,ans1,ans2);
	        		        fclose(fp);break;
					}break;
			        break;
				case '-':
					switch(opt3)
					{
						case '+':
							if((num1+num4)<c)return -1;
							else
							{
								c=num1+num4-c-1;
								ans1=ans2-ans1;
					if(ans1!=0&&c!=0)
		    			fprintf(fp,"答案%d：%d'%d/%d\n",y,c,ans1,ans2);
					else if(ans1==0)
						fprintf(fp,"答案%d：%d\n",y,c);
					else
		    			fprintf(fp,"答案%d：%d/%d\n",y,ans1,ans2);
	        		            fclose(fp);
							}break;
	        		    case '-':
	        		    	if(num1<(num4+c))return -1;
	        		    	else
	        		    	{
	        		    		c=num1-num4-c-1;
	        		    		ans1=ans2-ans1;
					if(ans1!=0&&c!=0)
		    			fprintf(fp,"答案%d：%d'%d/%d\n",y,c,ans1,ans2);
					else if(ans1==0)
						fprintf(fp,"答案%d：%d\n",y,c);
					else
		    			fprintf(fp,"答案%d：%d/%d\n",y,ans1,ans2);
	        		            fclose(fp);
							}break;
						case 'x':
							ans1=num2*num4;
							c=0;
							a=gcd(ans1,num3);
							ans1=ans1/a;
							ans2=ans2/a;
							while(ans1>=ans2)
							{
								ans1=ans1-ans2;
								c++;
							}
							c=num1-c-1;
							ans1=ans2-ans1;
					if(ans1!=0&&c!=0)
		    			fprintf(fp,"答案%d：%d'%d/%d\n",y,c,ans1,ans2);
					else if(ans1==0)
						fprintf(fp,"答案%d：%d\n",y,c);
					else
		    			fprintf(fp,"答案%d：%d/%d\n",y,ans1,ans2);
	        		        fclose(fp);break;
	        		    case '/':
	        		    	ans2=num3*num4;
	        		    	c=0;
	        		    	a=gcd(num2,ans2);
	        		    	ans1=num2/a;
	        		    	ans2=ans2/a;
	        		    	while(ans1>=ans2)
							{
								ans1=ans1-ans2;
								c++;
							}
							c=num1-c-1;
							ans1=ans2-ans1;
					if(ans1!=0&&c!=0)
		    			fprintf(fp,"答案%d：%d'%d/%d\n",y,c,ans1,ans2);
					else if(ans1==0)
						fprintf(fp,"答案%d：%d\n",y,c);
					else
		    			fprintf(fp,"答案%d：%d/%d\n",y,ans1,ans2);
	        		        fclose(fp);break;
					}break;
		            break;
			}
		}
		else
		if(opt3=='x')
		{
			int ans1;
			ans1=num3*num4;
			int ans2;
		    switch(opt1)
    	    {
	        	case '+':
	        		ans2=num1+num2;break;
        		case '-':
        			if(num1<num2)
						return -1;
	        		ans2=num1-num2;break;
	        }
			switch(opt2)
        	{
	        	case '+':
	        		ans=ans1+ans2;
	        		fprintf(fp,"答案%d：%d\n",y,ans);
	        		fclose(fp);break;
        		case '-':
        			if(ans1<ans2)
						return -1;
        			else
        			{
        				ans=ans1-ans2;
        				fprintf(fp,"答案%d：%d\n",y,ans);
	        	        fclose(fp);
					}break;
	        }
		}
		else
		if(opt3=='/')
		{
			c=0;
			int ans1,ans2;
			a=gcd(num3,num4);
			ans1=num3/a;
			ans2=num4/a;
			while(ans1>=ans2)
			{
				ans1=ans1-ans2;
				c++;
			}
			switch(opt1)
			{
				case '+':
					switch(opt2)
					{
						case '+':
							c=c+num1+num2;
					if(ans1!=0&&c!=0)
		    			fprintf(fp,"答案%d：%d'%d/%d\n",y,c,ans1,ans2);
					else if(ans1==0)
						fprintf(fp,"答案%d：%d\n",y,c);
					else
		    			fprintf(fp,"答案%d：%d/%d\n",y,ans1,ans2);
	        		        fclose(fp);break;
	        		    case '-':
	        		    	if((num1+num2)<c)
								return -1;
	        		    	else
	        		    	{
	        		    		c=num1+num2-c-1;
	        		    		ans1=ans2-ans1;
					if(ans1!=0&&c!=0)
		    			fprintf(fp,"答案%d：%d'%d/%d\n",y,c,ans1,ans2);
					else if(ans1==0)
						fprintf(fp,"答案%d：%d\n",y,c);
					else
		    			fprintf(fp,"答案%d：%d/%d\n",y,ans1,ans2);
	        		            fclose(fp);
							}break;
					}break;
				case '-':
					switch(opt2)
					{
						case '+':
							if((num1+c)<num2)
								return -1;
							else
							{
								c=num1+c-num2;
					if(ans1!=0&&c!=0)
		    			fprintf(fp,"答案%d：%d'%d/%d\n",y,c,ans1,ans2);
					else if(ans1==0)
						fprintf(fp,"答案%d：%d\n",y,c);
					else
		    			fprintf(fp,"答案%d：%d/%d\n",y,ans1,ans2);
	        		            fclose(fp);
							}break;
	        		    case '-':
	        		    	if(num1<(c+num2))
								return -1;
	        		    	else
	        		    	{
	        		    		c=num1-num2-c-1;
	        		    		ans1=ans2-ans1;
					if(ans1!=0&&c!=0)
		    			fprintf(fp,"答案%d：%d'%d/%d\n",y,c,ans1,ans2);
					else if(ans1==0)
						fprintf(fp,"答案%d：%d\n",y,c);
					else
		    			fprintf(fp,"答案%d：%d/%d\n",y,ans1,ans2);
	        		            fclose(fp);
							}break;
					}break;
			}
		}
	    else
	    if(opt1=='+')
	    {
	    	int ans1,ans2,ans;
	    	ans1=num1+num2;
	    	if(opt2=='+')
	    	{
	    		ans2=ans1+num3;
	    		if(opt3=='+')
	    		{
	    			ans=ans2+num4;
	    			fprintf(fp,"答案%d：%d\n",y,ans);
	    			fclose(fp);
				}
				else
				if(opt3=='-')
	    		{
	    			if(ans2<num4)return -1;
	    			else
	    			{
	    				ans=ans2-num4;
	    				fprintf(fp,"答案%d：%d\n",y,ans);
	    				fclose(fp);
					}
				}
	    	}
	    	else
			if(opt2=='-')
			{
				ans2=ans1-num3;
				if(opt3=='+')
	    		{
	    			if((ans2+num4)<0)
						return -1;
	    			else
	    			{
	    				ans=ans2+num4;
	    		    	fprintf(fp,"答案%d：%d\n",y,ans);
	    		    	fclose(fp);
					}
				}
				else
				if(opt3=='-')
	    		{
	    			if((ans2-num4)<0)
						return -1;
	    			else
	    			{
	    				ans=ans2-num4;
	    				fprintf(fp,"答案%d：%d\n",y,ans);
	    				fclose(fp);
					}
				}
			}
    	}
    	else
	    if(opt1=='-')
	    {
	    	int ans1,ans2,ans;
	    	ans1=num1-num2;
	    	if(opt2=='+')
	    	{
	    		ans2=ans1+num3;
	    		if(opt3=='+')
	    		{
	    			if((ans2+num4)<0)return -1;
	    			else
	    			{
	    				ans=ans2+num4;
	    		    	fprintf(fp,"答案%d：%d\n",y,ans);
	    		    	fclose(fp);
					}
				}
				else
				if(opt3=='-')
	    		{
	    			if(ans2<num4)return -1;
	    			else
	    			{
	    				ans=ans2-num4;
	    				fprintf(fp,"答案%d：%d\n",y,ans);
	    				fclose(fp);
					}
				}
	    	}
	    	else
			if(opt2=='-')
			{
				ans2=ans1-num3;
				if(opt3=='+')
	    		{
	    			if((ans2+num4)<0)return -1;
	    			else
	    			{
	    				ans=ans2+num4;
	    		    	fprintf(fp,"答案%d：%d\n",y,ans);
	    		    	fclose(fp);
					}
				}
				else
				if(opt3=='-')
	    		{
	    			if((ans2-num4)<0)return -1;
	    			else
	    			{
	    				ans=ans2-num4;
	    				fprintf(fp,"答案%d：%d\n",y,ans);
	    				fclose(fp);
					}
				}
			}
    	}
	return 0;
}

int question(int y,int r)//生成题目 
{
	FILE *fp;
	//srand((unsigned)time(0));
    int num;
	char str[7];
	str[0]=random(r)+48;
	str[1]=getOpt();
	str[2]=random(r)+48;
	str[3]=getOpt();
	str[4]=random(r)+48;
	str[5]=getOpt();
	str[6]=random(r)+48;
    num=rand()%3+1;
    
    //num=3,num1=3,num2=2,num3=3,num4=4,signal1='/',signal2='-',signal3='-';
    if(num==1)
    {	
		if(Answers1(y,str,r)==-1)
			return -1;
     	fp=fopen("Exercises.txt","a");
     	fprintf(fp,"四则运算题目%d：%c %c %c = \n",y,str[0],str[1],str[2]);
     	fclose(fp);
	}
	if(num==2)
	{
		if(Answers2(y,str,r)==-1)
			return -1;
     	fp=fopen("Exercises.txt","a");
     	fprintf(fp,"四则运算题目%d：%c %c %c %c %c = \n",y,str[0],str[1],str[2],str[3],str[4]);
     	fclose(fp);
		}
	if(num==3)
	{
		if(Answers3(y,str,r)==-1)
			return -1;
     	fp=fopen("Exercises.txt","a");
     	fprintf(fp,"四则运算题目%d：%c %c %c %c %c %c %c = \n",y,str[0],str[1],str[2],str[3],str[4],str[5],str[6]);
     	fclose(fp);
	}
	return 1;
} 

int main()
{
	srand((unsigned)time(NULL));
	FILE *fp;
	fp=fopen("Exercises.txt","w");
	fclose(fp);
	fp=fopen("Answers.txt","w");
	fclose(fp);
	int n,r;
	int y=1;
	char argv1[3];
    char argv2[3];
    //n=10,r=10;
	printf("Myapp.exe");
    scanf("%s",argv1);//-n
	scanf("%d",&n);;
	printf("Myapp.exe");
	scanf("%s",argv2);//-r
	scanf("%d",&r);
	if(!strcmp(argv1,"-n")&&!strcmp(argv2,"-r"))
	{
		while(n>0)
		{
			if(question(y,r)==-1)
			{
				continue;
			}
			y++;
			n--;
		}
	}
	else 
		printf("输入错误！请按如下格式输入：\nMyapp.exe-n 10\nMyapp.exe-r 10\n");
	return 0;
}