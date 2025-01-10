
#include "head.h"
void BuildNebrList()
{
	VecR dr;
	VecR invWid, rs, shift;
	VecI cc,m1v, m2v, vOff[]=OFFSET_VALS;
	real rrNebr;
	real fcVal, rr, rrCut, rri, rri3;
	real uVal;
	
	int j1,j2, n;
	int c,m1, m1x,m1y, m1z,m2,offset;
	rrNebr=Sqr(rCut+rNebrShell);

	VDiv(invWid, cells,region);
	/*invWid=cells/region, which is a cooeficient*/
	/*invWid~=1./rCut*/
	for(n=nMol;n<nMol+VProd(cells);n++) cellList[n]=-1; 
	/* initialize the array of cellList to -1, a meaningless value */
	DO_MOL 
	{
		VSAdd(rs,mol[n].r,0.5,region);
		/*rs=r+1/2*region,shift the coordinate half of the region size*/
		VMul(cc,rs,invWid);
		/*for simplicity, only use the x dimension. cc=rs/rCut, cc denotes the number of the cell?*/
		c=VLinear(cc,cells)+nMol;
		cellList[n]=cellList[c];
		cellList[c]=n;
		/*initialize the cellList*/
	}
	nebrTabLen=0;
	for(m1z=0;m1z<cells.z;m1z++)
	{
		for(m1y=0;m1y<cells.y;m1y++)
		{
			for(m1x=0;m1x<cells.x;m1x++)
			{
				VSet(m1v,m1x,m1y,m1z);/*m1v hold the current index of the cell*/
				m1=VLinear(m1v, cells)+nMol; /*m1 is the linearized index of the target array*/
				for(offset=0;offset<N_OFFSET;offset++)
				{
					VAdd(m2v,m1v,vOff[offset]);
					/*m2v is the index of the adjacent cells*/
					VZero(shift);
					/*initialzie shift*/
					VCellWrapAll();
					m2=VLinear(m2v,cells)+nMol;
					/*m2 is the linearized index of the adjacent cell*/
					for (j1=cellList[m1];j1>=0;j1=cellList[j1])
					{
						for(j2=cellList[m2];j2>=0;j2=cellList[j2])
						{
							if(m1!=m2||j2<j1)  /*m1!=m2; the mols are not in the same cell lattice; j2<j1:only calculate once of a-b, not a-b and b-a interactions*/
							{
								VSub(dr,mol[j1].r,mol[j2].r);
								/*dr is now the vector pointing from j2 to j1 */
								VVSub(dr,shift);	
								rr=VLenSq(dr); /*rr is the square of |dr|*/

								if(VLenSq(dr)<rrNebr)
									{
										if(nebrTabLen>=nebrTabMax)
											ErrExit(ERR_TOO_MANY_NEBRS);	
										nebrTab[2*nebrTabLen]=j1;
										nebrTab[2*nebrTabLen+1]=j2;
										++nebrTabLen;
									}
							}							
						}
					}
				}
			}
		}
	}
}
	

