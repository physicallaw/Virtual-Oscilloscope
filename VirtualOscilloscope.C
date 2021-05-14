//Title : Virtual Oscilloscope
//Authors : Ra Young-cheor (Dept. of Physics, '13), 2013550008

class TVirtualOscilloscope : public TGMainFrame 
{
private:
   TRootEmbeddedCanvas *fCanvas;
   TGLayoutHints       *fLcan;
   TF1                 *fFitFcn1, *fFitFcn2, *fFitFcn3;
   TGVerticalFrame     *fVframe1, *fVframe2, *fVframe3;
   TGHorizontalFrame   *fHframe1;
   TGLayoutHints       *fBly, *fBfly1, *fBfly2, *fBfly3, *fBfly4;
   TGHSlider           *fHslider1, *fHslider2, *fHslider3, *fHslider4, *fHslider5,
                       *fHslider6, *fHslider7, *fHslider8, *fHslider9;
   TGListBox           *fListBox;
   TList               *fSelected;
   TGTextButton        *show, *exit;
   TLegend             *fLegend; 
   int                 handle;

public:
   TVirtualOscilloscope();
   virtual ~TVirtualOscilloscope();

   void CloseWindow();
   void Slider();
   float Generator(int);
   void DoSelect();
   void DoExit();

   ClassDef(TVirtualOscilloscope, 0)
};

//______________________________________________________________________________
TVirtualOscilloscope::TVirtualOscilloscope() : TGMainFrame(gClient->GetRoot(),
                                                   100, 100, kHorizontalFrame)
{
   SetCleanup(kDeepCleanup);
   fCanvas = new TRootEmbeddedCanvas("Canvas", this, 360, 300);
   fLcan = new TGLayoutHints(kLHintsExpandY, 10, 10, 10, 10);
   AddFrame(fCanvas, fLcan);
   fCanvas->GetCanvas()->SetFillColor(kGreen-8);
   fCanvas->GetCanvas()->SetFrameFillColor(kGreen-8);
   fCanvas->GetCanvas()->SetBorderMode(0);
   fCanvas->GetCanvas()->SetGrid();

   fVframe1 = new TGVerticalFrame(this, 0, 0, 0);
   fHslider1 = new TGHSlider(fVframe1, 200, kSlider1|kScaleBoth,
                              -1, kHorizontalFrame,
                              GetDefaultFrameBackground());
   fHslider2 = new TGHSlider(fVframe1, 200, kSlider1|kScaleBoth,
                              -1, kHorizontalFrame,
                              GetDefaultFrameBackground());
   fHslider3 = new TGHSlider(fVframe1, 200, kSlider1|kScaleBoth,
                              -1, kHorizontalFrame,
                              GetDefaultFrameBackground());
   fHslider4 = new TGHSlider(fVframe1, 200, kSlider1|kScaleBoth,
                              -1, kHorizontalFrame,
                              GetDefaultFrameBackground());
   fHslider1->Connect("PositionChanged(Int_t)", "TVirtualOscilloscope", 
                      this, "Slider()");
   fHslider2->Connect("PositionChanged(Int_t)", "TVirtualOscilloscope", 
                      this, "Slider()");
   fHslider3->Connect("PositionChanged(Int_t)", "TVirtualOscilloscope", 
                      this, "Slider()");
   fHslider4->Connect("PositionChanged(Int_t)", "TVirtualOscilloscope", 
                      this, "Slider()");
   fHslider1->SetRange(-3.0,3.0);
   fHslider2->SetRange(0.0,10.0);
   fHslider3->SetRange(1.0,10.0);
   fHslider4->SetRange(-10.0,10.0);
   fHslider1->SetPosition(0.0);
   fHslider2->SetPosition(5.0);
   fHslider3->SetPosition(1.0);
   fHslider4->SetPosition(0.0);
   TGLabel *fLabel1 = new TGLabel(fVframe1, "VOLT/DIV");
   TGLabel *fLabel2 = new TGLabel(fVframe1, "Vertical Position");
   TGLabel *fLabel3 = new TGLabel(fVframe1, "TIME/DIV");
   TGLabel *fLabel4 = new TGLabel(fVframe1, "Horizontal Position");


   fHframe1 = new TGHorizontalFrame(fVframe1, 0, 0, 0);
   fListBox = new TGListBox(fHframe1);
   fSelected = new TList;
   fListBox->AddEntry("R circuit",1);
   fListBox->AddEntry("RL circuit",2);
   fListBox->AddEntry("RC circuit",3);
   fListBox->AddEntry("RLC circuit",4);
   fListBox->Resize(130,80);

   fVframe2 = new TGVerticalFrame(fHframe1, 0, 0, 0);
   show = new TGTextButton(fVframe2, "&Show");
   exit = new TGTextButton(fVframe2, "&Exit");
   show->SetToolTipText("Click here to print the selection you made");
   show->Connect("Pressed()", "TVirtualOscilloscope", this, "DoSelect()");
   exit->Connect("Pressed()", "TVirtualOscilloscope", this, "DoExit()");

   fVframe3 = new TGVerticalFrame(this, 0, 0, 0);
   fHslider5 = new TGHSlider(fVframe3, 200, kSlider1|kScaleBoth,
                              -1, kHorizontalFrame,
                              GetDefaultFrameBackground());
   fHslider6 = new TGHSlider(fVframe3, 200, kSlider1|kScaleBoth,
                              -1, kHorizontalFrame,
                              GetDefaultFrameBackground());
   fHslider7 = new TGHSlider(fVframe3, 200, kSlider1|kScaleBoth,
                              -1, kHorizontalFrame,
                              GetDefaultFrameBackground());
   fHslider8 = new TGHSlider(fVframe3, 200, kSlider1|kScaleBoth,
                              -1, kHorizontalFrame,
                              GetDefaultFrameBackground());
   fHslider9 = new TGHSlider(fVframe3, 200, kSlider1|kScaleBoth,
                              -1, kHorizontalFrame,
                              GetDefaultFrameBackground());
   fHslider5->Connect("PositionChanged(Int_t)", "TVirtualOscilloscope", 
                      this, "Slider()");
   fHslider6->Connect("PositionChanged(Int_t)", "TVirtualOscilloscope", 
                      this, "Slider()");
   fHslider7->Connect("PositionChanged(Int_t)", "TVirtualOscilloscope", 
                      this, "Slider()");
   fHslider8->Connect("PositionChanged(Int_t)", "TVirtualOscilloscope", 
                      this, "Slider()");
   fHslider9->Connect("PositionChanged(Int_t)", "TVirtualOscilloscope", 
                      this, "Slider()");
   fHslider5->SetRange(1.0,10.0);
   fHslider6->SetRange(-5.0,5.0);
   fHslider7->SetRange(1.0,10.0);
   fHslider8->SetRange(1.0,10.0);
   fHslider9->SetRange(1.0,10.0);
   fHslider5->SetPosition(1.0);
   fHslider6->SetPosition(0.0);
   fHslider7->SetPosition(1.0);
   fHslider8->SetPosition(1.0);
   fHslider9->SetPosition(1.0);
   TGLabel *fLabel5 = new TGLabel(fVframe3, "Voltage Values");
   TGLabel *fLabel6 = new TGLabel(fVframe3, "Frequency Values");
   TGLabel *fLabel7 = new TGLabel(fVframe3, "Resistor Values");
   TGLabel *fLabel8 = new TGLabel(fVframe3, "Inductor Values");
   TGLabel *fLabel9 = new TGLabel(fVframe3, "Capacitor Values");

   fBly = new TGLayoutHints(kLHintsLeft, 5, 5, 5, 5);
   fBfly1 = new TGLayoutHints(kLHintsExpandX, 5, 5, 5, 5);
   fBfly2 = new TGLayoutHints(kLHintsTop | kLHintsLeft, 5, 5, 5, 5);
   fBfly3 = new TGLayoutHints(kLHintsTop | kLHintsLeft, 10, 5, 5, 5);
   fBfly4 = new TGLayoutHints(kLHintsTop | kLHintsLeft, 5, 5, 10, 5);

   fVframe2->AddFrame(show, fBfly1);
   fVframe2->AddFrame(exit, fBfly1);

   fHframe1->AddFrame(fListBox, fBfly4);
   fHframe1->AddFrame(fVframe2, fBfly4);

   fVframe1->AddFrame(fHframe1, fBfly2);
   fVframe1->AddFrame(fLabel1, fBfly2);
   fVframe1->AddFrame(fHslider1, fBfly1);
   fVframe1->AddFrame(fLabel2, fBfly2);
   fVframe1->AddFrame(fHslider2, fBfly1);
   fVframe1->AddFrame(fLabel3, fBfly2);
   fVframe1->AddFrame(fHslider3, fBfly1);
   fVframe1->AddFrame(fLabel4, fBfly2);
   fVframe1->AddFrame(fHslider4, fBfly1);

   fVframe3->AddFrame(fLabel5, fBfly2);
   fVframe3->AddFrame(fHslider5, fBfly1);
   fVframe3->AddFrame(fLabel6, fBfly2);
   fVframe3->AddFrame(fHslider6, fBfly1);
   fVframe3->AddFrame(fLabel7, fBfly2);
   fVframe3->AddFrame(fHslider7, fBfly1);
   fVframe3->AddFrame(fLabel8, fBfly2);
   fVframe3->AddFrame(fHslider8, fBfly1);
   fVframe3->AddFrame(fLabel9, fBfly2);
   fVframe3->AddFrame(fHslider9, fBfly1);

   AddFrame(fVframe1, fBly);
   AddFrame(fVframe3, fBly);

   SetWindowName("Virtual Oscilloscope");
   MapSubwindows();
   Resize(GetDefaultSize());
   MapWindow();

   fLegend = new TLegend(0,0,0,0,"","b"); 
   fFitFcn1 = new TF1("fFitFcn1","[0]*[1]*sin([2]*[3]*x)",0,10);
   fFitFcn1->SetRange(0, 5);
   fFitFcn1->SetLineColor(kBlack);
   fFitFcn1->SetLineWidth(3);
   fFitFcn1->SetTitle("");
   fFitFcn2 = new TF1("fFitFcn2","[0]*[1]*sin([2]*[3]*x-3.14159/2)",0,10);
   fFitFcn2->SetRange(0, 5);
   fFitFcn2->SetLineColor(kRed);
   fFitFcn2->SetLineWidth(3);
   fFitFcn2->SetTitle("");
   fFitFcn3 = new TF1("fFitFcn3","[0]*[1]*sin([2]*[3]*x+3.14159/2)",0,10);
   fFitFcn3->SetRange(0, 5);
   fFitFcn3->SetLineColor(kCyan-9);
   fFitFcn3->SetLineWidth(3);
   fFitFcn3->SetTitle("");

   fListBox->Select(1);
}

//______________________________________________________________________________
TVirtualOscilloscope::~TVirtualOscilloscope()
{
   Cleanup();
}

//______________________________________________________________________________
void TVirtualOscilloscope::CloseWindow()
{
   delete this;
}

//______________________________________________________________________________
void TVirtualOscilloscope::Slider()
{
   fFitFcn1->SetParameters(exp(fHslider1->GetPosition()),
                           fHslider5->GetPosition()*Generator(1),
                           fHslider3->GetPosition(),
                           exp(fHslider6->GetPosition()));
   fFitFcn1->SetRange(fHslider2->GetPosition(),
                      fHslider2->GetPosition()+5);
   fFitFcn1->SetMinimum(fHslider4->GetPosition()-5);
   fFitFcn1->SetMaximum(fHslider4->GetPosition()+5);
   fFitFcn2->SetParameters(exp(fHslider1->GetPosition()),
                           fHslider5->GetPosition()*Generator(2),
                           fHslider3->GetPosition(),
                           exp(fHslider6->GetPosition()));
   fFitFcn2->SetRange(fHslider2->GetPosition(),
                      fHslider2->GetPosition()+5);
   fFitFcn2->SetMinimum(fHslider4->GetPosition()-5);
   fFitFcn2->SetMaximum(fHslider4->GetPosition()+5);
   fFitFcn3->SetParameters(exp(fHslider1->GetPosition()),
                           fHslider5->GetPosition()*Generator(3),
                           fHslider3->GetPosition(),
                           exp(fHslider6->GetPosition()));
   fFitFcn3->SetRange(fHslider2->GetPosition(),
                      fHslider2->GetPosition()+5);
   fFitFcn3->SetMinimum(fHslider4->GetPosition()-5);
   fFitFcn3->SetMaximum(fHslider4->GetPosition()+5);
   fLegend->Draw();
   fCanvas->GetCanvas()->Modified();
   fCanvas->GetCanvas()->Update();
}

//______________________________________________________________________________
float TVirtualOscilloscope::Generator(int i)
{
   float R = fHslider7->GetPosition(),
         Xl = exp(fHslider6->GetPosition())*fHslider8->GetPosition(),
         Xc = 1/(exp(fHslider6->GetPosition())*fHslider9->GetPosition()),
         Z;
  
   switch (handle) {
      case 1:
         return 1.;
      case 2:
         Z = sqrt(R*R+Xl*Xl); 
         if (i == 1) return R/Z;
         if (i == 2) return Xl/Z;
      case 3:
         Z = sqrt(R*R+Xc*Xc); 
         if (i == 1) return R/Z;
         if (i == 3) return Xc/Z;
      case 4:
         Z = sqrt(R*R+(Xl-Xc)*(Xl-Xc)); 
         if (i == 1) return R/Z;
         if (i == 2) return Xl/Z;
         if (i == 3) return Xc/Z;
      default:
         break;
   }
   return 0;
}

//______________________________________________________________________________
void TVirtualOscilloscope::DoSelect()
{
   fLegend->Clear();
   fLegend->AddEntry(fFitFcn1->Draw(""),"","");
   switch (fListBox->GetSelected()) {
      case 1:
         handle = 1;
         break;
      case 2:
         fLegend->AddEntry(fFitFcn2->Draw("lsame"),"","");
         handle = 2;
         break;
      case 3:
         fLegend->AddEntry(fFitFcn3->Draw("lsame"),"","");
         handle = 3;
         break;
      case 4:
         fLegend->AddEntry(fFitFcn2->Draw("lsame"),"","");
         fLegend->AddEntry(fFitFcn3->Draw("lsame"),"","");
         handle = 4;
         break;
      default:
         break;
   }
   Slider();
}


//______________________________________________________________________________
void TVirtualOscilloscope::DoExit()
{
   gApplication->Terminate(0);
}

//______________________________________________________________________________
void VirtualOscilloscope()
{
   new TVirtualOscilloscope();
}