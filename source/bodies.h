
class BODIES
{
	int numCurBody;
	int bodyCount;

public:

	BODY *body;

	BODIES(int bodyCount)
	{
	 numCurBody=0;
	 this->bodyCount=bodyCount;
	 body=new BODY[bodyCount];
	}

	//���������� ���������� ��� ������������� ����������� ��������� ��� (��� ��� �������? :) )
	void copy_BodiesPos_To_ModelsPos(RTM_MODEL  **model,int modelCount)
	{
		for(int i=0;i<modelCount;i++)
		{
		   if(model[i])
			   model[i]->SetPosition(body[numCurBody].x,body[numCurBody].y,body[numCurBody].z);
	
		   numCurBody++;
		   if(numCurBody>=bodyCount)
		 		numCurBody=0; ///////numCurBody=(++numCurBody)*(numCurBody<bodyCount); 
		}
	}

	//��������� ���� ���.����� 
	void moveAllBodies()
	{	
		for(int  j=0;j<bodyCount;j++)
			body[j].move();
	}

};
