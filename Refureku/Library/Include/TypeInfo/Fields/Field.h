#pragma once

#include <cassert>
#include <type_traits>

#include "TypeInfo/Fields/FieldBase.h"
#include "TypeInfo/Type.h"

namespace refureku
{
	class Field : public FieldBase
	{
		protected:
			/** Memory offset in bytes of this field in its owner class */
			uint32	memoryOffset	= 0u;

		public:
			Field()																	= delete;
			Field(std::string&&		name,
				  uint64			id				= 0u,
				  EAccessSpecifier	access			= EAccessSpecifier::Undefined,
				  Struct const*		ownerStruct		= nullptr,
				  Struct const*		introducedBy	= nullptr,
				  uint32			memoryOffset	= 0u)							noexcept;
			Field(Field const&)														= default;
			Field(Field&&)															= default;
			~Field()																= default;

			/**
			*	Get the data corresponding to this field in the provided instance
			*/
			template <typename DataType>
			DataType	getData(void* instance)										const noexcept;

			/**
			*	Set the data corresponding to this field in the provided instance
			*	This method is not safe if you provided a wrong typed data
			*/
			template <typename DataType>
			void		setData(void* instance, DataType&& data)					const noexcept;

			/**
			*	Get the data address corresponding to this field in the provided instance
			*/
			void*		getDataAddress(void* instance)								const noexcept;

			/**
			*	Copy dataSize bytes starting from data into the field in instance
			*/
			void		setData(void* instance, void const* data, uint64 dataSize)	const noexcept;

			Field& operator=(Field const&)	= default;
			Field& operator=(Field&&)		= default;
	};

	#include "TypeInfo/Fields/Field.inl"
}