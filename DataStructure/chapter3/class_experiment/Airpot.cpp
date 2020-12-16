#include<iostream>
#include<cmath>
#include<ctime>
using namespace std;
int t = 5;  
int ji = 0; 
int ou = 1; 
            
struct plane
{           
	int x = t; 
	int id = 0;
	bool k = 0;//1降落，0起飞
	double wait = 0;//记录等待起飞的时间
};          
            
class airport
{           
private:    
	plane m[101];
	bool k = 0;//1降落0起飞
	int fly = 6;
	int down = 0;
	double timefly = 0;
	double timedown = 0;
	double timedownleft = 0;
	int flyn = 0;
	int downn = 0;
	int jinji = 0;
	int shumu = 5;
public:     
	int getfly() { return fly; }
            
	void shumuchange() { shumu++; }
            
	void changestruct(int l) { m[l].k = 1; }
            
	int getdown() { return down; }
            
	int getjinji() { return jinji; }
            
	plane getplane(int i) { return m[i]; }
            
	void changek(int o) { k = o; }
            
	void changeshumu() { shumu = 2; }
            
	void examk() { if (k == 1) fly = 3; }
            
	int getshumu(){ return shumu; }
            
	void chushiid()
	{          
			for (int i = 0; i <= 5; i++)
			{        
				if (m[i].k == 0)
				{       
					m[i].id = 2 * ji + 1;
					ji++;  
				}       
				else    
				{       
					m[i].id = 2 * ou;
					ou++;  
				}       
			}        
	}//        
            
	void inid(int p)
	{          
		if (m[p].k == 0)
			m[p].id = 2 * ji - 1;
		else      
			m[p].id = 2 * ou;
	}          
            
	void out() 
	{          
			if (m[0].k == 0)
			{        
				fly = fly - 1;
				flyn++; 
				timefly = timefly + m[0].wait;
				cout << m[0].id << "出队" << endl;
			}        
			else     
			{        
				down = down - 1;
				downn++;
				timedown = timedown + m[0].wait;
				timedownleft = timedownleft + t - m[0].wait;
				cout << m[0].id << "出队" << endl;
			}        
			shumu--; 
			for (int i = 1; i <= shumu+1; i++)
			{        
				m[i - 1] = m[i];
			}        
	}//        
            
	void outmid(int x)
	{          
			for (int i = x; i < shumu; i++)
			{        
				m[i] = m[i + 1];
			}        
	}//        
            
	void in(bool x)
	{          
			m[shumu + 1].x = t;
			m[shumu + 1].k = x;
			if (x == 0)
				ji++;   
			else     
				ou++;   
			inid(shumu + 1);
	}//        
            
	void jinjiin(plane o)
	{          
		cout << shumu + 1 << endl;
		for (int i = shumu+1; i >= 0; i--)
			m[i] = m[i-1];
		cout << m[shumu].id << endl;
		m[0] = o; 
		jinji++;  
	}//        
            
	void pass()
	{          
		if (k == 1)
		{         
			for (int i = 0; i <= shumu; i++)
					m[i].x = m[i].x - 1;
		}         
		for (int i = 0; i <= shumu; i++)
		{         
			m[i].wait++;
		}         
	}//        
            
	void jinjipass()
	{          
		m[shumu - 1] = m[shumu];
		shumu--;  
	}          
            
	int exam(int s = 0)
	{          
			for (int i = s; i <= shumu; i++)
				if (m[i].x == 1)
					return i;
		return 0; 
	}//        
            
	double waitflypingjun()
	{          
		if (flyn == 0)
			return 0;
		else      
			return(double(timefly) / (flyn));
	}//        
            
	double waitdownpingjun()
	{          
		if (downn == 0)
			return 0;
		else      
			return(double(timedown) / double(downn));
	}//        
            
	double timedownpingjun()
	{          
		if (flyn == 0)
			return 0;
		else      
			return(double(timedownleft) / double(downn));
	}//        
            
	int nopower()
	{          
		int n = 0;
		if (k == 1)
		{         
			for (int i = 0; i <= shumu; i++)
			{        
				if (m[i].x == 1)
					n++;   
			}        
			return n;
		}         
		return 0; 
	}//        
            
	void show()
	{          
		cout << "当前状态显示" << endl;
		if (k == 0)
		{         
			for (int i = 0; i <= shumu; i++)
			{        
				cout << "ID:" << m[i].id << " 状态:";
				if (m[i].k == 0)
					cout << " 等待起飞";
				else    
					cout << " 等待降落";
				cout << " 剩余油量:" << m[i].x;
				cout << " 等待时间" << m[i].wait << endl;
			}        
		}         
		else      
		{         
			for (int i = 0; i <= shumu; i++)
			{        
				cout << "ID:" << m[i].id << " 状态:";
				if (m[i].k == 0)
					cout << " 等待起飞";
				else    
					cout << " 等待降落";
				cout << " 剩余油量:" << m[i].x;
				cout << " 等待时间" << m[i].wait << endl;
			}        
		}         
	}//        
            
	void addnew()
	{          
		int i1 = 2;
		int i2 = 2;
		int x = 0;
		if (k == 0)
		{         
			while (x <= i1)
			{        
				cout << "队列飞机数:" <<(shumu+1)<< endl;
				if (shumu > 99)
					break; 
				int shuru;
				cout << "输入对起飞队列的操作，0表示增加起飞的飞机，输入2退出" << endl;
				cin >> shuru;
				if (shuru == 2)
				{       
					break; 
				}       
				in(shuru);
				shumuchange();
				x++;    
				cout << "可以增加的飞机数目" << (i1 - x+1) << endl<<endl;
			}        
			cout << endl;
		}         
		if (k == 1)
		{         
			while (x <= i2)
			{        
				cout << "队列飞机数:" << (shumu+1) << endl;
				if (shumu > 99)
					break; 
				int shuru;
				cout << "输入对降落队列的操作，1表示增加降落的飞机，输入2退出" << endl;
				cin >> shuru;
				if (shuru == 2)
				{       
					break; 
				}       
				in(shuru);
				shumuchange();
				int f;  
				cout << "输入等待时间：";
				cin >> f;
				m[shumu].x = f;
				x++;    
				cout << "可以增加的飞机数目" << (i2 - x+1) << endl<<endl;
			}        
			cout << endl;
		}         
	}//        
};          
            
class Line  
{           
private:    
	double timefly = 0;
	double timedown = 0;
	double timeflypingjun = 0;
	double timedownpingjun = 0;
	double fly = 0;
	double down = 0;
	int k = 0; 
public:     
	void sum(plane x)
	{          
		if (x.k == 0)
		{         
			fly++;   
			timefly = timefly + x.wait;
			timeflypingjun = timefly / fly;
		}         
		else      
		{         
			down++;  
			timedown = timedown + x.wait;
			timedownpingjun = timedown / down;
		}          
	}           
	void show() 
	{           
		cout << "已起飞飞机数：" << fly << " 总等待时长：" << timefly << " 平均等待时间：" << timeflypingjun<<endl;
		cout << "已降落飞机数：" << down << " 总等待时长：" << timedown << " 平均等待时间：" << timedownpingjun<<endl;
	}           
};           
             
int main(void)
{            
	srand(time(0));
	int jinjiqifei = 0;
	int shuru = 0;
	airport line1;
	airport line2;
	plane* x = new plane[3];
	Line* y = new Line[3];
	for (int i = 0; i <= 5; i++)
		line2.changestruct(i);
	line1.chushiid();
	line2.chushiid();
	line2.changek(1);
	cout << "起飞队列" << endl;
	line1.show(); 
	cout << "降落队列" << endl;
	line2.show(); 
	cout << "输入0继续，输入1退出" << endl;
	int m = 0;  
	int exam1 = 0; int exam2 = 0;
	plane move; 
	cin >> m;   
	int p = 0;  
	ou--;       
	exam2 = line2.nopower();
	while (m == 0)
	{           
		cout << endl << "_________________"<<endl;
		line1.pass();
		line2.pass();
		line1.addnew();
		line2.addnew();
		cout << endl<<line2.getshumu()<<endl;
		cout << "起飞队列" << endl;
		line1.show();
		cout << "降落队列" << endl;
		line2.show();
		exam2 = line2.nopower();
		jinjiqifei = jinjiqifei + exam2;
		           
		if (exam2 > 3)
		{          
			cout << "无法继续进行起落";
			break;    
		}          
		if (exam2 == 0)
		{          
			if (line1.getshumu() > line2.getshumu())
			{         
				x[0] = line1.getplane(0);
				line1.out();
				x[1] = line1.getplane(0);
				line1.out();
				x[2] = line2.getplane(0);
				line2.out();
			}         
			else      
			{         
				x[0] = line1.getplane(0);
				line1.out();
				x[1] = line2.getplane(0);
				line2.out();
				x[2] = line2.getplane(0);
				line2.out();
			}         
		}          
		else       
		{          
			p = 1;    
			if (exam2 == 1)
			{         
			    int r = line2.exam();
				if (r != 0)
				{        
					move = line2.getplane(line2.exam());
					line2.jinjiin(move);
					line2.outmid(r);
             
					x[0] = line2.getplane(0);
					line2.out();
					x[1] = line1.getplane(0);
					line1.out();
					x[2] = line1.getplane(0);
					line1.out();
				}        
				else     
				{        
					x[0] = line1.getplane(0);
					line1.out();
					x[1] = line2.getplane(0);
					line2.out();
					x[2] = line2.getplane(0);
					line2.out();
				}        
			}         
			if (exam2 == 2)
			{         
				int r = line2.exam();
				move = line2.getplane(line2.exam());
				line2.outmid(r);
				line2.jinjiin(move);
             
				move = line2.getplane(line2.exam(r));
				r = line2.exam(r);
				line2.outmid(r);
				line2.jinjiin(move);
             
				x[0] = line2.getplane(0);
				line2.out();
				x[1] = line2.getplane(0);
				line2.out();
				x[2] = line1.getplane(0);
				line1.out();
			}         
			if (exam2 == 3)
			{         
				int r = line2.exam();
				move = line2.getplane(line2.exam());
				line2.outmid(r);
				line2.jinjiin(move);
             
				move = line2.getplane(line2.exam(r));
				r = line2.exam(r);
				line2.outmid(r);
				line2.jinjiin(move);
             
				move = line2.getplane(line2.exam(r));
				r = line2.exam(r);
				line2.outmid(r);
				line2.jinjiin(move);
             
				x[0] = line2.getplane(0);
				line2.out();
				x[1] = line2.getplane(0);
				line2.out();
				x[2] = line2.getplane(0);
				line2.out();
			}         
		}          
             
		if (p == 1)
		{          
			y[2].sum(x[0]);
			y[1].sum(x[2]);
			y[0].sum(x[1]);
		}          
		else       
		{          
			y[2].sum(x[0]);
			y[1].sum(x[2]);
			y[0].sum(x[1]);
		}          
		cout<<endl << "起飞队列" << endl;
		line1.show();
		cout << "降落队列" << endl;
		line2.show();
		cout << endl;
		cout << "跑道1：" << endl;
		y[0].show();
		cout << "跑道1：" << endl;
		y[1].show();
		cout << "跑道3：" << endl;
		y[2].show();
		cout << "输入0继续，输入1退出" << endl;
		cin >> m;  
		p = 0;     
	}           
	return 0;   
}            
            