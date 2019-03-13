	#include<iostream>
	#include<string>
	#include<math.h>

	using namespace std;
	class point{
	private:
		float x;
		float y;
	public:
		point()
		{
			x=0;
			y=0;
		}
		void setx(float v)
		{
			x=v;
		}
		void sety(float v)
		{
			y=v;
		}
		float getx()
		{
			return x;
		}
		float gety()
		{
			return y;
		}
		float distance (point p)
		{
			return sqrt(pow(x-p.getx(),2)+pow(y-p.gety(),2));
		}
		// فيه primeter
		float maxx(point a[],int size)
		{
			float max=a[0].getx();
			int m=0;
			for(int i=0;i<size;i++)
			{
			if(a[i].getx()>max)
			{
				m=i; max=a[i].getx();
			}
			}
			return max;
		}
		float maxy(point a[],int size)
		{
			float max=a[0].gety();
			int m=0;
			for(int i=0;i<size;i++)
			{
			if(a[i].gety()>max)
			{
				m=i; max=a[i].gety();
			}
			}
			return max;
		}
		float miny(point a[],int size)
		{
			float min=a[0].gety();
			int m=0;
			for(int i=0;i<size;i++)
			{
			if(a[i].gety()<min)
			{
				m=i; min=a[i].gety();
			}
			}
			return min;
		}
		 float minx(point a[],int size)
		{
			float min=a[0].getx();
			int m=0;
			for(int i=0;i<size;i++)
			{
			if(a[i].getx()<min)
			{
				m=i; min=a[i].getx();
			}
			}
			return min;
		}
		bool isPointInsideRectangle(point arr[])//point call fn is point which is checked and arr[] is points of rectangle
		{
		float a1,a2,a3,a4;
		a1=x*arr[0].gety()-arr[0].getx()*y+arr[0].getx()*arr[1].gety()-arr[1].getx()*arr[0].gety()+arr[1].getx()*y-x*arr[1].gety();
		a2=x*arr[2].gety()-arr[2].getx()*y+arr[2].getx()*arr[1].gety()-arr[1].getx()*arr[2].gety()+arr[1].getx()*y-x*arr[1].gety();
		a3=x*arr[2].gety()-arr[2].getx()*y+arr[2].getx()*arr[3].gety()-arr[3].getx()*arr[2].gety()+arr[3].getx()*y-x*arr[3].gety();
		a4=x*arr[0].gety()-arr[0].getx()*y+arr[0].getx()*arr[3].gety()-arr[3].getx()*arr[0].gety()+arr[3].getx()*y-x*arr[3].gety();
		a1=abs(a1);a1=0.5*a1;
		a2=abs(a2);a2=0.5*a2;
		a3=abs(a3);a3=0.5*a3;
		a4=abs(a4);a4=0.5*a4;
		float areaOFRectangle=arr[0].getx()*arr[1].gety()-arr[1].getx()*arr[0].gety()+arr[1].getx()*arr[2].gety()-arr[2].getx()*arr[1].gety()+arr[2].getx()*arr[3].gety()-arr[3].getx()*arr[2].gety()+arr[3].getx()*arr[0].gety()-arr[0].getx()*arr[3].gety();
		areaOFRectangle=abs(areaOFRectangle);areaOFRectangle=0.5*areaOFRectangle;
		if(a1+a2+a3+a4==areaOFRectangle) return true;
		return false;
		}
		bool isallpointsOfarrayinsideRectangleOrnot(point arr[],int size,point rec[])//size==noofpoints in polygon
		{
		int check=0;//لو طلع في الاخر يساوي عدد النقط معني كدا كل النقط واقعين جو المستطيل
		for(int i=0;i<size;i++)
		{
			if(arr[i].isPointInsideRectangle(rec)) check++;
		}
		if(check==size) return true;
		return false;
		}
	};
	class polygon{
	private:
		point arr[100];
		int nopoints;
	public:
		void setpoint(point a,int i)
		{
			arr[i].setx(a.getx());
			arr[i].sety(a.gety());
		}
	point getpoint(int i)
	{
		return arr[i];
	}
	void setnopoints(int n)
	{
		nopoints=n;
	}
	int getnopoints()
	{
		return nopoints;
	}
	float maxofx(polygon n[],int size)
	{
		point s;
		float max=s.maxx(n[0].arr,n[0].getnopoints());
		int m=0;
		for(int i=0;i<=size;i++)
		{
		  point m;
		  float temp=m.maxx(n[i].arr,n[i].getnopoints());
		if(temp>max)
			max=temp;
		}
	return max;
	}
	float maxofy(polygon n[],int size)
	{
		point s;
		float max=s.maxy(n[0].arr,n[0].getnopoints());
		int m=0;
		for(int i=0;i<size;i++)
		{
		  point m;
		  float temp=m.maxy(n[i].arr,n[i].getnopoints());
		if(temp>max)
			max=temp;
		}
	return max;
	}
	float minofx(polygon n[],int size)
	{
		point s;
		float min=s.minx(n[0].arr,n[0].getnopoints());
		int m=0;
		for(int i=0;i<size;i++)
		{
		  point m;
		  float temp=m.minx(n[i].arr,n[i].getnopoints());
		if(temp<min)
			min=temp;
		}
	return min;
	}
	float minofy(polygon n[],int size)
	{
		point s;
		float min=s.miny(n[0].arr,n[0].getnopoints());
		int m=0;
		for(int i=0;i<size;i++)
		{
		  point m;
		  float temp=m.miny(n[i].arr,n[i].getnopoints());
		if(temp<min)
			min=temp;
		}
	return min;
	}
	   float perimeter () // رقم المضلع بس i
	   {
	   float perimeter=0;
	   for(int j=0;j<nopoints;j++)
	   {
	   if(j==nopoints-1)
		   perimeter+=arr[0].distance(arr[j]);
	   else perimeter+=arr[j].distance(arr[j+1]);
	   }
	   return perimeter;
	   }
	   void decreasenopoints()
	   {
   
		   nopoints--;
	   }
	   void plotPointsOfPolygon()
	   {
		   cout<<"("<<arr[0].getx()<<","<<arr[0].gety()<<")";
	   for(int j=1;j<nopoints;j++)
	   {
		 cout<<","<<"("<<arr[j].getx()<<","<<arr[j].gety()<<")";
	   }
   
	   }
	   void IDOfpolygonhaveelpoint(polygon a[],int size,string s) //size==count1
	   {
		   int k=0;int plot[100];
		   string input=s.substr(1);
	   float x,y;
	   x=atof(input.c_str());
	   input=input.substr(input.find(",")+1);
	   y=atof(input.c_str());
	   for(int i=0;i<size;i++)
	   {
		   for(int j=0;j<a[i].getnopoints();j++)
		   {
			   if(a[i].getpoint(j).getx()==x&&a[i].getpoint(j).gety()==y)
			  {
				  plot[k]=i+1;k++;break;
			  }
		   }
	   }
	   if(k==0) cout<<"none";
	   else {
	   cout<<plot[0];
	   for(int i=1;i<k;i++)
		   cout<<","<<plot[i];
	   
	   
	   }
	   }
	   void List_Polygons_PointsMoren(polygon a[],int size,int n)//size==count1
	   {
		   int j=0;int plot[100];
		   for(int i=0;i<size;i++)
		   {
			   if(a[i].getnopoints()>n)
			   {
				   plot[j]=i+1;j++;
			   }
		   }
		   if(j==0) cout<<"none";
		   else
		   {
		   cout<<plot[0];
		   for(int i=1;i<j;i++)
			   cout<<","<<plot[i];
		   
		   }
	   }
	   void List_Polygons_PointsEqualn(polygon a[],int size,int n)//size==count1
	   {
		   int j=0; int plot[100];
		   for(int i=0;i<size;i++)
		   {
			   if(a[i].getnopoints()==n)
			   {
				   plot[j]=i+1;
				   j++;
			   }
		   }
        if(j==0) cout<<"none";
		   else
		   {
		   cout<<plot[0];
		   for(int i=1;i<j;i++)
			   cout<<","<<plot[i];
		   
		   }	
	   }
	   void List_Polygons_Pointslessn(polygon a[],int size,int n)//size==count1
	   {
		   int j=0; int plot[100];
		   for(int i=0;i<size;i++)
		   {
			   if(a[i].getnopoints()<n)
			   {
				   plot[j]=i+1;
				    j++;
			   }
		   }
           if(j==0) cout<<"none";
		   else
		   {
		   cout<<plot[0];
		   for(int i=1;i<j;i++)
			   cout<<","<<plot[i];
		   
		   }		
	   }
	void List_Points_PolygonsMoren (float arrx[],float arry[],int count2,polygon p[],int count1 ,int n)//مسكت النقطة عدت بيها علي كل النقط
	{
		int s=0;
		float plotx[10000];
		float ploty[10000];
		for(int i=0;i<count2;i++)
		{
			int countToBeComperedTon=0;//صفرته وانا داخل للنقطة اللي بعدها
		   for(int j=0;j<count1;j++)
		   {
			   for(int k=0;k<p[j].getnopoints();k++)
			   {
				   if(arrx[i]==p[j].getpoint(k).getx()&&arry[i]==p[j].getpoint(k).gety())
				   {
					   countToBeComperedTon++;
					   break;
				   } //بريك عشان يخش علي المضلع اللي بعده
			   }
		   }
		   if(countToBeComperedTon>n)
		   {
			   plotx[s]=arrx[i];
			   ploty[s]=arry[i];
			   s++;
		   }
		}
		if(s==0) cout<<"none";
		else
		{
		cout<<"("<<plotx[0]<<","<<ploty[0]<<")";
		for(int i=1;i<s;i++)
		cout<<","<<"("<<plotx[i]<<","<<ploty[i]<<")";

		}
	}
	void  List_Points_PolygonsLessn (float arrx[],float arry[],int count2,polygon p[],int count1 ,int n)
	{
        int s=0;
		float plotx[10000];
		float ploty[10000];		
		for(int i=0;i<count2;i++)
		{
			int countToBeComperedTon=0;//صفرته وانا داخل للنقطة اللي بعدها
		   for(int j=0;j<count1;j++)
		   {
			   for(int k=0;k<p[j].getnopoints();k++)
			   {
				   if(arrx[i]==p[j].getpoint(k).getx()&&arry[i]==p[j].getpoint(k).gety()){countToBeComperedTon++;break;} //بريك عشان يخش علي المضلع اللي بعده
			   }
		   }
		   if(countToBeComperedTon<n) 
		   {
			   plotx[s]=arrx[i];
			   ploty[s]=arry[i];
			   s++;
		   }
		}
        if(s==0) cout<<"none";
		else
		{
		cout<<"("<<plotx[0]<<","<<ploty[0]<<")";
		for(int i=1;i<s;i++)
		cout<<","<<"("<<plotx[i]<<","<<ploty[i]<<")";

		}

	}
	void List_Points_PolygonsEqualn (float arrx[],float arry[],int count2,polygon p[],int count1 ,int n)
	{
        int s=0;
		float plotx[10000];
		float ploty[10000];	
		for(int i=0;i<count2;i++)
		{
			int countToBeComperedTon=0;//صفرته وانا داخل للنقطة اللي بعدها
		   for(int j=0;j<count1;j++)
		   {
			   for(int k=0;k<p[j].getnopoints();k++)
			   {
				   if(arrx[i]==p[j].getpoint(k).getx()&&arry[i]==p[j].getpoint(k).gety()){countToBeComperedTon++;break;} //بريك عشان يخش علي المضلع اللي بعده
			   }
		   }
		   if(countToBeComperedTon==n)
		   {
			  plotx[s]=arrx[i];
			   ploty[s]=arry[i];
			   s++;
		   }
		}
        if(s==0) cout<<"none";
		else
		{
		cout<<"("<<plotx[0]<<","<<ploty[0]<<")";
		for(int i=1;i<s;i++)
		cout<<","<<"("<<plotx[i]<<","<<ploty[i]<<")";

		}

	}
	void  List_Triangles (polygon a[],int size)//size==count1;
	{
		int j=0;int plot[100];
		for(int i=0;i<size;i++)
		{
			if(a[i].getnopoints()==3)
			{
			 plot[j]=i+1; j++;
			}
	
		}
		if(j==0) cout<<"none";
	else
	{
		cout<<plot[0];
		for(int i=1;i<j;i++)
			cout<<","<<plot[i];
	}
	}
	void  List_Rectangles(polygon a[],int size)//size==count1;
	{
	  int j=0;int plot[100];
	   for(int i=0;i<size;i++)
	   {
		float m1=((a[i].getpoint(0).gety()-a[i].getpoint(1).gety())/(a[i].getpoint(0).getx()-a[i].getpoint(1).getx()))*((a[i].getpoint(1).gety()-a[i].getpoint(2).gety())/(a[i].getpoint(1).getx()-a[i].getpoint(2).getx()));
		   if(a[i].getnopoints()==4&&a[i].getpoint(0).distance(a[i].getpoint(1))==a[i].getpoint(2).distance(a[i].getpoint(3))&&a[i].getpoint(1).distance(a[i].getpoint(2))==a[i].getpoint(0).distance(a[i].getpoint(3))&&(m1==-1||((a[i].getpoint(0).gety()-a[i].getpoint(1).gety())==0&&(a[i].getpoint(1).getx()-a[i].getpoint(2).getx())==0)||((a[i].getpoint(1).gety()-a[i].getpoint(2).gety())==0&&(a[i].getpoint(0).getx()-a[i].getpoint(1).getx())==0)))
		   {
		   plot[j]=i+1; j++;
		   } 
	   }
	   if(j==0) cout<<"none";
	else
	{
		cout<<plot[0];
		for(int i=1;i<j;i++)
			cout<<","<<plot[i];
	}
	}
	void List_Trapezoid (polygon a[],int size)//size==count1;
	{
	 int j=0;int plot[100];
	for(int i=0;i<size;i++)
	{
		float m1=(a[i].getpoint(0).gety()-a[i].getpoint(1).gety())/(a[i].getpoint(0).getx()-a[i].getpoint(1).getx());
		float m2=(a[i].getpoint(3).gety()-a[i].getpoint(2).gety())/(a[i].getpoint(3).getx()-a[i].getpoint(2).getx());
		float m3=(a[i].getpoint(1).gety()-a[i].getpoint(2).gety())/(a[i].getpoint(1).getx()-a[i].getpoint(2).getx());
		float m4=(a[i].getpoint(0).gety()-a[i].getpoint(3).gety())/(a[i].getpoint(0).getx()-a[i].getpoint(3).getx());
		if((a[i].getnopoints()==4&&m1==m2&&m3!=m4)||(a[i].getnopoints()==4&&m3==m4&&m1!=m2))
			{
				plot[j]=i+1; j++;
			}
	}
	if(j==0) cout<<"none";
	else
	{
		cout<<plot[0];
		for(int i=1;i<j;i++)
			cout<<","<<plot[i];
	}
	}
 
	float Polygon_Arean()
	{
		float area=0;
		for(int i=0;i<getnopoints();i++)
		{
			if(i==getnopoints()-1)
				area+=arr[i].getx()*arr[0].gety()-arr[i].gety()*arr[0].getx();
			else area+=arr[i].getx()*arr[i+1].gety()-arr[i].gety()*arr[i+1].getx();
		}
	area=abs(area);area=area/2;
	return area;
	}
	void Polygons_Area_Range(polygon a[],int size,float minArea,float maxArea)
	{
	  int plot[100];
	  int j=0;
	  for(int i=0;i<size;i++)
	  {
		  if(a[i].Polygon_Arean()>=minArea&&a[i].Polygon_Arean()<=maxArea)
		  {
		  plot[j]=i+1;
		  j++;
		  }
	  }
	  if(j==0) cout<<"none";
	  else
	  {
	  cout<<plot[0];
	  for(int i=1;i<j;i++)
		  cout<<","<<plot[i];
	  }
	}

	void plotpolygonsIDsinsideGivenRectangle(polygon arry[],int size,point rec[])//size==count1;
	{
		int plot[100];int j=0;
		for(int i=0;i<size;i++)
		{
			if(arry[i].arr[0].isallpointsOfarrayinsideRectangleOrnot(arry[i].arr,arry[i].getnopoints(),rec) )//arr[0] zy wseet ya call fn w 5alas
			{
				plot[j]=i+1;j++;
			}
		}
		if(j==0) cout<<"none";
		else 
		{
		cout<<plot[0];
		for(int i=1;i<j;i++)
			cout<<","<<plot[i];
		}
	}
	bool isPolygoninsideCircle(float cx,float cy,float r)
	{
		point center;
		center.setx(cx);
		center.sety(cy);
		float d;int flag=0;
		for(int i=0;i<nopoints;i++)//nopoints of polygon which call fn;
		{
			d=arr[i].distance(center);
		   
			if(d>r) return false;
		}
		return true;
	}
	void plotIDsofpolygons_insidecircle(polygon arry[],int size,float cx,float cy,float r)
	{
		int j=0;int plot[100];
		for(int i=0;i<size;i++)
		{
			if(arry[i].isPolygoninsideCircle(cx,cy,r) )
			{
				plot[j]=i+1;j++;
			}
		}
		if(j==0) cout<<"none";
		else 
		{
		cout<<plot[0];
		for(int i=1;i<j;i++)
			cout<<","<<plot[i];
		}
	}
	void Polygons_Enclosing_Point(polygon p[],int count1,float pointx,float pointy)
	{
		int plot[100];
		int j=0;
		float area=0;
		for(int i=0;i<count1;i++)
		{
			for(int k=0;k<p[i].getnopoints();k++)
			{
				if(k==p[i].getnopoints()-1)
				{
				area+=0.5*abs(pointx*p[i].arr[k].gety()-p[i].arr[k].getx()*pointy+p[i].arr[k].getx()*p[i].arr[0].gety()-p[i].arr[0].getx()*p[i].arr[k].gety()+p[i].arr[0].getx()*pointy-p[i].arr[0].gety()*pointx);
				}
				else area+=0.5*abs(pointx*p[i].arr[k].gety()-p[i].arr[k].getx()*pointy+p[i].arr[k].getx()*p[i].arr[k+1].gety()-p[i].arr[k+1].getx()*p[i].arr[k].gety()+p[i].arr[k+1].getx()*pointy-p[i].arr[k+1].gety()*pointx);
			}
			if(area==p[i].Polygon_Arean())
			{
				plot[j]=i+1;j++;
			}
			area=0;
		}
		if(j==0) cout<<"none";
		else
		{
		cout<<plot[0];
		for(int i=1;i<j;i++)
			cout<<","<<plot[i];
		}
	}
	bool is_intersecting(polygon a,polygon b)
	{
		
	float xo,xf,c,m,pointy,pointx,yo,yf;
	float area=0;
	for(int i=0;i<a.getnopoints();i++)
	{
		if(i==a.getnopoints()-1)
		{
		  m=(a.arr[i].gety()-a.arr[0].gety())/(a.arr[i].getx()-a.arr[0].getx());
		  c=a.arr[0].gety()-m*a.arr[0].getx();
		  if(a.arr[i].getx()<a.arr[0].getx())
		  {
			  xo=a.arr[i].getx();   xf=a.arr[0].getx();
		  }
		  else
		  {
		  xo=a.arr[0].getx();      xf=a.arr[i].getx();
		  }
		  if(a.arr[i].gety()<a.arr[0].gety())
		  {
		  			  yo=a.arr[i].gety();   yf=a.arr[0].gety();
		  }
		  else
		  {
		  		  yo=a.arr[0].gety();      yf=a.arr[i].gety();
		  }
		}
		else	
		{
			m=(a.arr[i+1].gety()-a.arr[i].gety())/(a.arr[i+1].getx()-a.arr[i].getx());
			c=a.arr[i].gety()-m*a.arr[i].getx();
			if(a.arr[i+1].getx()<a.arr[i].getx())
			{
			xo=a.arr[i+1].getx();xf=a.arr[i].getx();
			}
			else
			{
			xo=a.arr[i].getx();   xf=a.arr[i+1].getx();
			}
			if(a.arr[i+1].gety()<a.arr[i].gety())
			{
			yo=a.arr[i+1].gety();yf=a.arr[i].gety();
			}
			else
			{
			yo=a.arr[i].gety();   yf=a.arr[i+1].gety();
			}
		}
		// لحد كدا كونت الضلع عدي علي النقط يتاعته بقي
		if(xo==xf)
		{
		  for(pointy=yo;pointy<=yf;pointy+=0.001)
		{
					  pointx=xo;
		for(int k=0;k<b.getnopoints();k++)
			{
				if(k==b.getnopoints()-1)
				{
				area+=0.5*abs(pointx*b.arr[k].gety()-b.arr[k].getx()*pointy+b.arr[k].getx()*b.arr[0].gety()-b.arr[0].getx()*b.arr[k].gety()+b.arr[0].getx()*pointy-b.arr[0].gety()*pointx);
				}
				else area+=0.5*abs(pointx*b.arr[k].gety()-b.arr[k].getx()*pointy+b.arr[k].getx()*b.arr[k+1].gety()-b.arr[k+1].getx()*b.arr[k].gety()+b.arr[k+1].getx()*pointy-b.arr[k+1].gety()*pointx);
			}
			if(area==b.Polygon_Arean()) return true;
	
			area=0;
		}
		}
		else if(yo==yf)
		{
		for(pointx=xo;pointx<=xf;pointx+=0.001)
		{
						pointy=yo;
		for(int k=0;k<b.getnopoints();k++)
			{
				if(k==b.getnopoints()-1)
				{
				area+=0.5*abs(pointx*b.arr[k].gety()-b.arr[k].getx()*pointy+b.arr[k].getx()*b.arr[0].gety()-b.arr[0].getx()*b.arr[k].gety()+b.arr[0].getx()*pointy-b.arr[0].gety()*pointx);
				}
				else area+=0.5*abs(pointx*b.arr[k].gety()-b.arr[k].getx()*pointy+b.arr[k].getx()*b.arr[k+1].gety()-b.arr[k+1].getx()*b.arr[k].gety()+b.arr[k+1].getx()*pointy-b.arr[k+1].gety()*pointx);
			}
			if(area==b.Polygon_Arean()) return true;
			area=0;
		}
		}
		else
		{
		for(pointx=xo;pointx<=xf;pointx+=0.001)
		{
		 pointy=m*pointx+c;
	
	
		for(int k=0;k<b.getnopoints();k++)
			{
				if(k==b.getnopoints()-1)
				{
				area+=0.5*abs(pointx*b.arr[k].gety()-b.arr[k].getx()*pointy+b.arr[k].getx()*b.arr[0].gety()-b.arr[0].getx()*b.arr[k].gety()+b.arr[0].getx()*pointy-b.arr[0].gety()*pointx);
				}
				else area+=0.5*abs(pointx*b.arr[k].gety()-b.arr[k].getx()*pointy+b.arr[k].getx()*b.arr[k+1].gety()-b.arr[k+1].getx()*b.arr[k].gety()+b.arr[k+1].getx()*pointy-b.arr[k+1].gety()*pointx);
			}
			if(area==b.Polygon_Arean()) return true;
	
			area=0;
		}
	    }
	}
		 return false;

	}
	bool Intersecting_Group(polygon a[],int count)
	{

		for(int i=0;i<count;i++)
		{
		for(int k=i+1;k<count;k++)
		{
			if(!(a[i].is_intersecting(a[i],a[k])))            return false;
		}
		}
		return true;
	}

	void Largest_Intersecting_Pair(polygon a[],int count,int&n,int&m)
	{
		int flag=0;float area=0;
	for(int i=0;i<count;i++)
	{
	for(int k=i+1;k<count;k++)
	{
			if(a[i].is_intersecting(a[i],a[k]))
			{
				if(flag==0)
				{
					n=i;m=k;area=a[i].Polygon_Arean()+a[k].Polygon_Arean();flag=1;
				}
				else
				{
					if(a[i].Polygon_Arean()+a[k].Polygon_Arean()>area)
					{
					n=i;m=k;area=a[i].Polygon_Arean()+a[k].Polygon_Arean();
					}
			
				}
		
			}
	}

	}

	}

	};
	int main()
	{
		string in;
		getline(cin,in);
		
		int i,j,count1;count1=1;
		//count1 for no of polygons
		for(i=0;i<in.length();i++)
		{
			if(in[i]== ';')            
				count1++;                  
		}
		// count2 for no of points
		int count2=0;                           
	
		for(i=0;i<in.length();i++)
		{
			if(in[i]== ')')                 
				count2++;                  
		}
		
		 while(1) 
		 {
			 
		 string temp=in;
		 polygon p[100];
		int count3=0; //count3 for no of points in each polygon
		j=0;int n=0;
		while(j<count1)
		{
		for(i=n;i<temp.length();i++)
		{
		if(temp[i]=='(')
			count3++;
		if(temp[i]==';'||temp[i]==']')
		{
			p[j].setnopoints(count3);count3=0;j++;n=i;

		}
		}
		}
	float x,y;
	 i=0; j=0;
	 float arrx[10000];float arry[10000];int change=0;// هننقل كل النقط في ارري عشان نعرف نعدي علي كل المضلعات نقارن النقط و نعرف نحدد النقط المتكررة فيهمlevel2 
		string::size_type indexofendy;
		string::size_type indexofstartx;
		string::size_type indexofendx;
		while(j<count1)
		{
	   while(i<p[j].getnopoints())
	   {
		indexofstartx=temp.find("(");
		indexofendx=temp.find(",");
		int diff=indexofendx-indexofstartx;
		x=atof(temp.substr(indexofstartx+1,diff-1).c_str());
	   temp=temp.substr(indexofendx+1);
	   indexofendy=temp.find(")");
	   y=atof(temp.substr(0,indexofendy).c_str());
	   temp=temp.substr(indexofendy+2);
		point s;
	   s.setx(x);
	   s.sety(y);
	   p[j].setpoint(s,i);
	   i++;
	   arrx[change]=x;
	   arry[change]=y;
	   change++;
	   }
	   j++;
	   i=0;
	}
		//
		// بس لازم نشيل من ارراكس و ارر واي النقط المتكررة عشان ميطبعش النقطة مرتين
		int count22=count2; //بتاع عد النقط من غير تكرار اللي هنبعته لل فنكشن بدل كونت 2
		for(i=0;i<count22;i++)
		{
		for(j=i+1;j<count22;j++)
		{
		if(arrx[i]==arrx[j]&&arry[i]==arry[j])
		{
		for(int k=j;k<count22;k++)
		{
			arrx[k]=arrx[k+1];arry[k]=arry[k+1];
		}
		count22--;i=0;j=i+1;
		}
		}
		}
		//
		float minx,maxx,miny,maxy;
		polygon whichcallfn;
		minx=whichcallfn.minofx(p,count1);
		maxx=whichcallfn.maxofx(p,count1);
		miny=whichcallfn.minofy(p,count1);
		maxy=whichcallfn.maxofy(p,count1);
		   
		string operation;
		cin>>operation;
		// does not need removal of reduandant
		if(operation=="Point_Polygons"||operation=="List_Points_Polygons")
		{
		if(operation=="List_Points_Polygons")
		{
			string more_less_equal;
			cin>>more_less_equal;
			int no;cin>>no;
			if(more_less_equal=="More")
			{
				p[0].List_Points_PolygonsMoren(arrx,arry,count22,p,count1,no);cout<<"\n";
			}
			if(more_less_equal=="Less")
			{
				p[0].List_Points_PolygonsLessn(arrx,arry,count22,p,count1,no);cout<<"\n";
			}
			if(more_less_equal=="Equal")
			{
				p[0].List_Points_PolygonsEqualn(arrx,arry,count22,p,count1,no);cout<<"\n";
			}
		}
		else
		{
			string elpoint;
			cin>>elpoint;
			p[0].IDOfpolygonhaveelpoint(p,count1,elpoint);
		}
		

		}
		else
		{
int countred=0;
		 for(int k=0;k<count1;k++)
		 {
			 int size=p[k].getnopoints();
		 //1stcaseofred;;;
			 a:
			 if(p[k]. getpoint(0).getx()==p[k]. getpoint(size-1).getx()&&p[k]. getpoint(0).gety()==p[k]. getpoint(size-1).gety())
		 {
			  for(int i=size-1;i<99;i++)
				  p[k]. setpoint(p[k]. getpoint(i+1),i);
		 size--;
		 countred++;
		 p[k].decreasenopoints();
		 goto a;
		 }
		 //2ndcaseofred;;;
		 for(int i=0;i<size;i++)
		 {
			 if(p[k]. getpoint(i).getx()==p[k].getpoint(i+1).getx()&&p[k].getpoint(i).gety()==p[k].getpoint(i+1).gety())
			{
				for(int j=i;j<99;j++)
					p[k]. setpoint(p[k].getpoint(j+1),j);
			size--;countred++;i=0;
			p[k].decreasenopoints();
			}
		 }
		 //3rdcaseofred;;;
		 for(int i=0;i<size-2;i++)
		 {
			 if((p[k].getpoint(i).gety()-p[k].getpoint(i+1).gety())/(p[k].getpoint(i).getx()-p[k].getpoint(i+1).getx())==(p[k].getpoint(i+1).gety()-p[k].getpoint(i+2).gety())/(p[k].getpoint(i+1).getx()-p[k].getpoint(i+2).getx()))
			{
			for(int j=i+1;j<99;j++)
				p[k].setpoint(p[k].getpoint(j+1),j);
			size--;countred++;i=0;
			p[k].decreasenopoints();
			}
		 }
		 //4th case
		 b:
		 if((p[k].getpoint(size-2).gety()-p[k].getpoint(size-1).gety())/(p[k].getpoint(size-2).getx()-p[k].getpoint(size-1).getx())==(p[k].getpoint(size-1).gety()-p[k].getpoint(0).gety())/(p[k].getpoint(size-1).getx()-p[k].getpoint(0).getx()))
		 {
		   for(int i=size-1;i<99;i++)
			   p[k].setpoint(p[k].getpoint(i+1),i);
		  size--;
		 countred++;
		 p[k].decreasenopoints();
		 goto b;
		 }
		 //5th case
		 c:
		 if((p[k].getpoint(0).gety()-p[k].getpoint(1).gety())/(p[k].getpoint(0).getx()-p[k].getpoint(1).getx())==(p[k].getpoint(size-1).gety()-p[k].getpoint(0).gety())/(p[k].getpoint(size-1).getx()-p[k].getpoint(0).getx()))
		 {
		   for(int i=0;i<99;i++)
			   p[k].setpoint(p[k].getpoint(i+1),i);
		  size--;
		 countred++;
		 p[k].decreasenopoints();
		 goto c;
		 }
		 }
		 if(operation=="Number_Polygons") 
		 {
			 cout<<count1;
			 cout<<"\n";
		 }
		 else if(operation=="Total_Number_Points")
		 {
			 cout<<count2;
			 cout<<"\n";
		 }
		 else if(operation=="Minimum_X")
		 {
			 cout<<minx;cout<<"\n";
		 }
		 else if(operation=="Maximum_X")
		 {
		    cout<<maxx;cout<<"\n";
		 }
		 else if(operation=="Minimum_Y")
		 {
		   cout<<miny;cout<<"\n";
		 }
		 else if(operation=="Maximum_Y")
		 {
		 cout<<maxy;cout<<"\n";
		 }
		 else if(operation=="Enclosing_Rectangle")
		 {
			 cout<<"("<<minx<<","<<miny<<"),("<<maxx<<","<<miny<<"),("<<maxx<<","<<maxy<<"),("<<minx<<","<<maxy<<")";cout<<"\n";
		 }
		 else if(operation=="Total_Redundant_Points")
		 {
			 cout<<countred;cout<<"\n";
		 }
		 else if(operation=="Quit")
		 {
			 break;
		 }
		 else if(operation=="Polygon_Points")
		 {
			 int numberofpolygon;
			 cin>>numberofpolygon;
			 p[numberofpolygon-1].plotPointsOfPolygon();
		 }
		 else if(operation=="List_Polygons_Points")
		 {
		 string MorLorE;
		 cin>>MorLorE;
		 int numberOfpoints;
		 cin>>numberOfpoints;
		 if(MorLorE=="More")
		 {
			 p[0].List_Polygons_PointsMoren(p,count1,numberOfpoints);cout<<"\n";
		 }
		 if(MorLorE=="Less")
		 {
			 p[0].List_Polygons_Pointslessn(p,count1,numberOfpoints);cout<<"\n";
		 }
		 if(MorLorE=="Equal")
		 {
			 p[0].List_Polygons_PointsEqualn(p,count1,numberOfpoints);cout<<"\n";
		 }
		 }
		 else if(operation=="Polygon_Perimeter")
		 {
		 int Id;
		 cin>>Id;
		 Id--;
		cout<<p[Id].perimeter();cout<<"\n";
		 }
		 else if(operation=="List_Triangles")
		 {
			 p[0].List_Triangles(p,count1);cout<<"\n";
		 }
		 else if(operation=="List_Rectangles")
		 {
			 p[0].List_Rectangles(p,count1);cout<<"\n";
		 }
		 else if(operation=="List_Trapezoid")
		 {
			 p[0].List_Trapezoid(p,count1);cout<<"\n";
		 }
		 else if(operation=="Inside_Rectangle")
		 {
		 string rectangle;
		 cin>>rectangle;
		 point rect[4];
		 rectangle=rectangle.substr(1);
		 rect[0].setx(atof(rectangle.c_str()));
		 rectangle=rectangle.substr(rectangle.find(",")+1);
		 rect[0].sety(atof(rectangle.c_str()));
		 rectangle=rectangle.substr(rectangle.find("(")+1);
		 rect[1].setx(atof(rectangle.c_str()));
		 rectangle=rectangle.substr(rectangle.find(",")+1);
		 rect[1].sety(atof(rectangle.c_str()));
		 rectangle=rectangle.substr(rectangle.find("(")+1);
		 rect[2].setx(atof(rectangle.c_str()));
		 rectangle=rectangle.substr(rectangle.find(",")+1);
		 rect[2].sety(atof(rectangle.c_str()));
		 rectangle=rectangle.substr(rectangle.find("(")+1);
		 rect[3].setx(atof(rectangle.c_str()));
		 rectangle=rectangle.substr(rectangle.find(",")+1);
		 rect[3].sety(atof(rectangle.c_str()));
		 p[0].plotpolygonsIDsinsideGivenRectangle(p,count1,rect);
		 cout<<"\n";
		 }
		 else if(operation=="Inside_Circle")
		 {
		    string pointANDradius;
			cin>>pointANDradius;
		    float cx,cy,r;
			pointANDradius=pointANDradius.substr(1);
			cx=atof(pointANDradius.c_str());
			pointANDradius=pointANDradius.substr(pointANDradius.find(",")+1);
			cy=atof(pointANDradius.c_str());
			pointANDradius=pointANDradius.substr(pointANDradius.find(",")+1);
			r=atof(pointANDradius.c_str());
			p[0].plotIDsofpolygons_insidecircle(p,count1,cx,cy,r);//p[0] member in class call fn wseet
			cout<<"\n";
		 }
		 else if(operation=="Polygon_Area")
		 {
		 int Number;
		 cin>>Number;
		 cout<<p[Number-1].Polygon_Arean();
		 cout<<"\n";
		 }
		 else if(operation=="Polygons_Area_Range")
		 {
		   float minArea,maxArea;
		   string Range;
		   cin>>Range;
		   minArea=atof(Range.c_str());
		   Range=Range.substr(Range.find(",")+1);
		   maxArea=atof(Range.c_str());
		   p[0].Polygons_Area_Range(p,count1,minArea,maxArea);
		   cout<<"\n";
		 }
		 else if(operation=="Polygons_Enclosing_Point")
		 {
		   string ThePoint;
		   cin>>ThePoint;
		   ThePoint=ThePoint.substr(1);
		   float pointx,pointy;
		   pointx=atof(ThePoint.c_str());
		   ThePoint=ThePoint.substr(ThePoint.find(",")+1);
		   pointy=atof(ThePoint.c_str());
		   p[0].Polygons_Enclosing_Point(p,count1,pointx,pointy);
		   cout<<"\n";
		 }

		 else if(operation=="Is_Intersecting")
		 {
		 string IDSof2polygons;
		 cin>>IDSof2polygons;
		 int ID1,ID2;
		 ID1=atof(IDSof2polygons.c_str());
		 IDSof2polygons=IDSof2polygons.substr(IDSof2polygons.find(",")+1);
		 ID2=atof(IDSof2polygons.c_str());
		 ID1--;ID2--;
		 if(p[0].is_intersecting(p[ID1],p[ID2]))//p[0] member ycall elfn w 5alas;
			 cout<<"True";
		 else cout<<"False";
		 
		 }
		 else if(operation=="Intersecting_Group")
		 {
		 string intersectingNumbers;
		 cin>>intersectingNumbers;
		 int count=0;
		 for(int i=0;i<intersectingNumbers.length();i++)
		 {
			 if(intersectingNumbers[i]==',')
				 count++;
		 }
		 polygon a[100];
		 int num;
		 num=atof(intersectingNumbers.c_str());
		 a[0]=p[num-1];
		 for(int k=1;k<=count;k++)
		 {
			 intersectingNumbers=intersectingNumbers.substr(intersectingNumbers.find(",")+1);
		     num=atof(intersectingNumbers.c_str());
			 a[k]=p[num-1];
		 }
		 if(p[0].Intersecting_Group(a,count+1)) cout<<"True";
		 else cout<<"False";
		 cout<<"\n";
		 }
		 else if(operation=="Largest_Intersecting_Pair")
		 {
			 int Id1,Id2;
			 p[0].Largest_Intersecting_Pair(p,count1,Id1,Id2);//p[0] any member call fn from class
		     cout<<Id1+1<<","<<Id2+1;
			 cout<<"\n";
		 }
		}		 
		 }
		system("pause");
	return 0;
	}

