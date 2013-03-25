#include <iostream>
#include <stdlib.h>
#include "../include/dxf_2D.h" 

using namespace std;

	int main()
	{	
		//////////////////// hut design /////////////////
		dxf d("hut.dxf");
	
		// hut upper-left portion
		point	pp1(0, 20), 
			    pp2(-14, 0), 
			    pp3(14, 0);  

		line	l1(pp1, pp2, "Layer3", d),
		     	l2(pp1, pp3, "Layer3", d);

		// hut lower- left portion
		point 	pp4(-9, 6), 
			    pp5(-9, -27), 
			    pp6(9, 6), 
			    pp7(9, -30), 
			    pp8(-4, -15), 
			    pp9(-4, -27.560),
			    pp10(4, -15),
			    pp11(4, -28.880),
			    pp12(0, -13),
			    pp13(62, 2),
			    pp14(55, -28),
			    pp15(56, 1.45),
			    pp16(48, 22),
			    pp17(0, 10);
	
		line 	l3(pp4, pp5, "Layer5", d), 
			    l4(pp6, pp7, "Layer5", d), 
			    l5(pp5, pp7, "Layer5", d),
			    l6(pp8, pp9 , "Layer4", d),
			    l7(pp10, pp11, "Layer4", d),
			    l8(pp8, pp12, "Layer2", d),
		    	l9(pp10, pp12, "Layer2", d),
			    l10(pp3, pp13, "Layer4", d),
		    	l11(pp7, pp14, "Layer5", d),
		    	l12(pp14, pp15, "Layer5", d),
			    l13(pp1, pp16, "Layer4", d),
			l14(pp13, pp16, "Layer4", d);

		// circle at the upper left 
		circle 	c1(pp17, 2, "Layer4", d, 1, 256);

		// lower right-center window
		point 	pp18(20, -10),
			    pp19(26, -15),
		    	pp20(40,-10),
		    	pp21(46, -15),
		    	p1(19, -9),
		    	p2(27, -16),
		    	p3(39, -9),
			    p4(47, -16);

	  rectangle	r1(pp18, pp19, "Layer4", d, 1,"ansi31"),
			    r2(pp20, pp21, "Layer4", d, 1, "ansi31"),
			    r3(p1, p2, "Layer5",d),
			    r4(p3, p4, "Layer5",d);

		// uppper right lines horizontally and vertically		
		point	pp22(3.088, 16),
			    pp23(50.545, 18),
			    pp24(5.890, 12),
			    pp25(53.345, 14),
			    pp26(8.680, 8),
			    pp27(56.150,10),
			    pp28(11.480, 4),
			    pp29(58.940, 6),
			    pp30(6, 20.040),
		    	pp31(20, 0.450),
		    	pp32(12, 20.290),
		    	pp33(26, 0.700),
		    	pp34(18, 20.540),
    			pp35(32, 0.950),
	    		pp36(24, 20.790),
		     	pp37(38, 1.2),
			    pp38(30, 21.040),
    			pp39(44, 1.450),
	    		pp40(36, 21.290),
		    	pp41(50, 1.7),
    			pp42(42, 21.540),
	    		pp43(56, 1.950);
		
		line 	l15(pp22, pp23, "Layer2" , d),
		    	l16(pp24, pp25, "Layer2", d),
			    l17(pp26, pp27, "Layer2", d),
			    l18(pp28, pp29, "Layer2", d),
			    l19(pp30, pp31, "Layer2", d),
		    	l20(pp32, pp33, "Layer2", d),
			    l21(pp34, pp35, "Layer2", d),
    			l22(pp36, pp37, "Layer2", d),
	    		l23(pp38, pp39, "Layer2", d),
		    	l24(pp40, pp41, "Layer2", d),
			    l25(pp42, pp43, "Layer2", d);

		// upper left design and lower gate design
		point 	pp44(0, 8),
			    pp45(-8.7, 0),
			    pp46(8.7, 0),
    			pp47(0, 12),
	    		pp48(0, -14),
		    	pp49(-3.730, -16),
		    	pp50(3.730, -16),
			    pp51(0, 19.6);

		line	l26(pp44, pp45, "Layer4", d),
			    l27(pp44, pp46, "Layer4", d),
			    l28(pp51, pp47, "Layer4", d),
			    l29(pp44, pp4, "Layer4", d),
    			l30(pp44, pp6, "Layer4", d),
	    		l31(pp48, pp49, "Layer3", d),
		    	l32(pp48, pp50, "Layer3", d);

		// owner of the hut
		point	pt1(0, -20),
    			pt2(-1.3, -20),
	    		pt3(1.3, -20),
		    	pt4(-0.4, -19.7),
			    pt5(0.4, -19.7),
	    		pt6(0,-20.5),
    			pt7(-1.4, -21),
    			pt8(1.4,-24),
	    		pt9(-0.5,-24),
		    	pt10(-0.5, -27),
			    pt11(0.5, -24),
    			pt12(0.5, -27.3),
	    		pt13(-1.2, -27.5),
		    	pt14(-0.3, -27.9),
			    pt15(-1.4, -22),
    			pt16(-3.8,-22.5),
	    		pt17(1.4, -22),
		    	pt18(3.8, -22.5),
			    pt19(0, -21.5),
    			pt20(0, -24),
    			pt21(0.2, -21.5),
    			pt22(0.2, -23.5),
	    		pt23(0.2, -22.5);

		circle 	cc1(pt1, 1, "Layer1", d),
		    	cc2(pt2, 0.3, "Layer1", d),
			    cc3(pt3, 0.3, "Layer1", d),
    			cc4(pt4, 0.1, "Layer1", d),
	    		cc5(pt5, 0.1, "Layer1", d);

		line	l33(pt1,pt6,"Layer1", d);

	  rectangle	r5(pt7, pt8, "Layer1", d);
	
    	line	li1(pt19, pt20, "Layer1", d);
	
    	circle 	cc6(pt21, 0.2, "Layer1", d),
	    		cc7(pt22, 0.2, "Layer1", d),
		    	cc8(pt23, 0.2, "Layer1", d);

		line	l34(pt9,  pt10, "Layer1", d),
			    l35(pt11, pt12, "Layer1", d),
			    l36(pt10, pt13, "Layer1", d),
			    l37(pt12, pt14, "Layer1", d),
	    		l38(pt15, pt16, "Layer1", d),
		    	l39(pt17, pt18, "Layer1", d);

		// sun circle and rays
		point	psun(-40, 25),
    			p1_ray1(-40, 22),
	    		p2_ray1(-39, 15 ),
		    	p1_ray2(-38, 24),
			    p2_ray2(-33, 17),
    			p1_ray3(-37.5, 26.5),
	    		p2_ray3(-28, 20),
		    	p1_ray4(-42.5, 24),
			    p2_ray4(-46, 15),
    			p1_ray5(-43, 25.5),
	    		p2_ray5(-52, 20);
		
        circle 	sun(psun, 3, "Layer2", d, 1, 2);

		line	ray1(p1_ray1, p2_ray1, "Layer2", d),
		    	ray2(p1_ray2, p2_ray2, "Layer2", d),
			    ray3(p1_ray3, p2_ray3, "Layer2", d),
			    ray4(p1_ray4, p2_ray4, "Layer2", d),
			    ray5(p1_ray5, p2_ray5, "Layer2", d);

		//saving file
		d.save();
  
		return 0 ;
	
	}



