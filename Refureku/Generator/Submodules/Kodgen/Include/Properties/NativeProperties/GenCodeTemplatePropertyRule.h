/**
*	Copyright (c) 2020 Julien SOYSOUVANH - All Rights Reserved
*
*	This file is part of the Kodgen library project which is released under the MIT License.
*	See the README.md file for full license details.
*/

#pragma once

#include <string>
#include <unordered_set>

#include "Properties/ComplexPropertyRule.h"

namespace kodgen
{
	class GenCodeTemplatePropertyRule : public ComplexPropertyRule
	{
		public:
			/** Names of GeneratedCodeTemplate registered to the FileGenerator. */
			std::unordered_set<std::string>	validTemplateNames;

			GenCodeTemplatePropertyRule()									= default;
			GenCodeTemplatePropertyRule(GenCodeTemplatePropertyRule const&)	= default;
			GenCodeTemplatePropertyRule(GenCodeTemplatePropertyRule&&)		= default;
			virtual ~GenCodeTemplatePropertyRule()							= default;

			virtual bool	isMainPropSyntaxValid(std::string const& mainProperty,
												  EntityInfo::EType	 entityType)				const noexcept override;

			virtual bool	isSubPropSyntaxValid(std::string const& subProperty,
												 uint8				subPropIndex,
												 std::string&		out_errorDescription)		const noexcept override;

			virtual bool	isPropertyGroupValid(PropertyGroup const&	propertyGroup,
												 uint8					propertyIndex,
												 std::string&			out_errorDescription)	const noexcept override;

			virtual bool	isEntityValid(EntityInfo const& entity,
										  uint8				propertyIndex,
										  std::string&		out_errorDescription)				const noexcept override;
	};
}