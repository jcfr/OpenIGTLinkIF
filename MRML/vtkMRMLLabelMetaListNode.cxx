/*=auto=========================================================================

Portions (c) Copyright 2009 Brigham and Women's Hospital (BWH) All Rights Reserved.

See Doc/copyright/copyright.txt
or http://www.slicer.org/copyright/copyright.txt for details.

Program:   3D Slicer
Module:    $RCSfile: vtkMRMLGradientAnisotropicDiffusionFilterNode.cxx,v $
Date:      $Date: 2006/03/17 15:10:10 $
Version:   $Revision: 1.2 $

=========================================================================auto=*/

// OpenIGTLink includes
#include <igtlOSUtil.h>
#include <igtlMessageBase.h>
#include <igtlMessageHeader.h>

// VTK includes
#include <vtkObjectFactory.h>

// MRML includes
#include <vtkMRMLLabelMetaListNode.h>
#include <vtkMRMLScene.h>

// STD includes
#include <string>
#include <iostream>
#include <sstream>
#include <map>

//------------------------------------------------------------------------------
vtkMRMLNodeNewMacro(vtkMRMLLabelMetaListNode);

//----------------------------------------------------------------------------
vtkMRMLLabelMetaListNode::vtkMRMLLabelMetaListNode()
{
  this->LabelMetaList.clear();
}

//----------------------------------------------------------------------------
vtkMRMLLabelMetaListNode::~vtkMRMLLabelMetaListNode()
{
}

//----------------------------------------------------------------------------
void vtkMRMLLabelMetaListNode::WriteXML(ostream& of, int nIndent)
{
  // Start by having the superclass write its information
  Superclass::WriteXML(of, nIndent);

  //of << " serverPort=\"" << this->ServerPort << "\" ";
  //of << " restrictDeviceName=\"" << this->RestrictDeviceName << "\" ";
}

//----------------------------------------------------------------------------
void vtkMRMLLabelMetaListNode::ReadXMLAttributes(const char** atts)
{
  vtkMRMLNode::ReadXMLAttributes(atts);

  const char* attName;
  const char* attValue;

  /*
  const char* serverHostname = "";
  int port = 0;
  int type = -1;
  int restrictDeviceName = 0;
  */

  while (*atts != NULL)
    {
    attName = *(atts++);
    attValue = *(atts++);

    /*
    if (!strcmp(attName, "connectorType"))
      {
      if (!strcmp(attValue, "SERVER"))
        {
        type = TYPE_SERVER;
        }
      else if (!strcmp(attValue, "CLIENT"))
        {
        type = TYPE_CLIENT;
        }
      else
        {
        type = TYPE_NOT_DEFINED;
        }
      }
    if (!strcmp(attName, "serverHostname"))
      {
      serverHostname = attValue;
      }
    if (!strcmp(attName, "serverPort"))
      {
      std::stringstream ss;
      ss << attValue;
      ss >> port;
      }
    if (!strcmp(attName, "restrictDeviceName"))
      {
      std::stringstream ss;
      ss << attValue;
      ss >> restrictDeviceName;;
      }
    */
    }

  /*
  switch(type)
    {
    case TYPE_SERVER:
      this->SetTypeServer(port);
      this->SetRestrictDeviceName(restrictDeviceName);
      break;
    case TYPE_CLIENT:
      this->SetTypeClient(serverHostname, port);
      this->SetRestrictDeviceName(restrictDeviceName);
      break;
    default: // not defined
      // do nothing
      break;
    }
  */
}

//----------------------------------------------------------------------------
// Copy the node's attributes to this object.
// Does NOT copy: ID, FilePrefix, Name, VolumeID
void vtkMRMLLabelMetaListNode::Copy(vtkMRMLNode *anode)
{

  Superclass::Copy(anode);
  /*
  vtkMRMLLabelMetaListNode *node = (vtkMRMLLabelMetaListNode *) anode;
  */

  /*
  int type = node->GetType();

  switch(type)
    {
    case TYPE_SERVER:
      this->SetType(TYPE_SERVER);
      this->SetTypeServer(node->GetServerPort());
      this->SetRestrictDeviceName(node->GetRestrictDeviceName());
      break;
    case TYPE_CLIENT:
      this->SetType(TYPE_CLIENT);
      this->SetTypeClient(node->GetServerHostname(), node->GetServerPort());
      this->SetRestrictDeviceName(node->GetRestrictDeviceName());
      break;
    default: // not defined
      // do nothing
      this->SetType(TYPE_NOT_DEFINED);
      break;
    }
  */
}

//----------------------------------------------------------------------------
void vtkMRMLLabelMetaListNode::ProcessMRMLEvents( vtkObject *caller, unsigned long event, void *callData )
{
  Superclass::ProcessMRMLEvents(caller, event, callData);

  /*
  MRMLNodeListType::iterator iter;
  for (iter = this->OutgoingMRMLNodeList.begin(); iter != this->OutgoingMRMLNodeList.end(); iter ++)
    {
    vtkMRMLNode* node = vtkMRMLNode::SafeDownCast(caller);
    if (node == *iter)
      {
      int size;
      void* igtlMsg;
      vtkIGTLToMRMLBase* converter = this->MRMLIDToConverterMap[node->GetID()];
      if (converter->MRMLToIGTL(event, node, &size, &igtlMsg))
        {
        int r = this->SendData(size, (unsigned char*)igtlMsg);
        if (r == 0)
          {
          // TODO: error handling
          //std::cerr << "ERROR: send data." << std::endl;
          }
        return;
        }
      }
    }
  */
}

//----------------------------------------------------------------------------
void vtkMRMLLabelMetaListNode::PrintSelf(ostream& os, vtkIndent indent)
{
  vtkMRMLNode::PrintSelf(os,indent);
}


//----------------------------------------------------------------------------
int  vtkMRMLLabelMetaListNode::GetNumberOfLabelMetaElement()
{
  return this->LabelMetaList.size();
}

//----------------------------------------------------------------------------
void vtkMRMLLabelMetaListNode::AddLabelMetaElement(LabelMetaElement element)
{
  this->LabelMetaList.push_back(element);
}

//----------------------------------------------------------------------------
void vtkMRMLLabelMetaListNode::GetLabelMetaElement(int index, LabelMetaElement* element)
{
  if (index >= 0 && index < (int) this->LabelMetaList.size())
    {
    *element = this->LabelMetaList[index];
    }
  else
    {
    element->DeviceName = "";
    }
}

//----------------------------------------------------------------------------
void vtkMRMLLabelMetaListNode::ClearLabelMetaElement()
{
  this->LabelMetaList.clear();
}
