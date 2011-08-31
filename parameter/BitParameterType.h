/* <auto_header>
 * <FILENAME>
 * 
 * INTEL CONFIDENTIAL
 * Copyright © 2011 Intel 
 * Corporation All Rights Reserved.
 * 
 * The source code contained or described herein and all documents related to
 * the source code ("Material") are owned by Intel Corporation or its suppliers
 * or licensors. Title to the Material remains with Intel Corporation or its
 * suppliers and licensors. The Material contains trade secrets and proprietary
 * and confidential information of Intel or its suppliers and licensors. The
 * Material is protected by worldwide copyright and trade secret laws and
 * treaty provisions. No part of the Material may be used, copied, reproduced,
 * modified, published, uploaded, posted, transmitted, distributed, or
 * disclosed in any way without Intel’s prior express written permission.
 * 
 * No license under any patent, copyright, trade secret or other intellectual
 * property right is granted to or conferred upon you by disclosure or delivery
 * of the Materials, either expressly, by implication, inducement, estoppel or
 * otherwise. Any license under such intellectual property rights must be
 * express and approved by Intel in writing.
 * 
 *  AUTHOR: Patrick Benavoli (patrickx.benavoli@intel.com)
 * CREATED: 2011-06-01
 * UPDATED: 2011-07-27
 * 
 * 
 * </auto_header>
 */
#pragma once

#include <stdint.h>

#include "TypeElement.h"

class CParameterAccessContext;

class CBitParameterType : public CTypeElement
{
public:
    CBitParameterType(const string& strName);

    // From IXmlSink
    virtual bool fromXml(const CXmlElement& xmlElement, CXmlSerializingContext& serializingContext);

    // Conversion
    bool asInteger(const string& strValue, uint32_t& uiValue, CParameterAccessContext& parameterAccessContext) const;
    void asString(const uint32_t& uiValue, string& strValue, CParameterAccessContext& parameterAccessContext) const;

    // Bit Size
    uint32_t getBitSize() const;

    // CElement
    virtual string getKind() const;
private:
    // Instantiation
    virtual CInstanceConfigurableElement* doInstantiate() const;
    // Max value
    uint32_t getMaxValue() const;
    // Biwise mask
    uint32_t getMask() const;
    // Check data has no bit set outside available range
    bool isEncodable(uint32_t uiData) const;

    // Pos in bits
    uint32_t _uiBitPos;
    // Size in bits
    uint32_t _uiBitSize;
};