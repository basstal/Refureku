/**
*	Copyright (c) 2021 Julien SOYSOUVANH - All Rights Reserved
*
*	This file is part of the Refureku library project which is released under the MIT License.
*	See the README.md file for full license details.
*/

#pragma once

#include "Refureku/Config.h"
#include "Refureku/Utility/Pimpl.h"
#include "Refureku/TypeInfo/Variables/EVarFlags.h"
#include "Refureku/TypeInfo/Functions/EFunctionFlags.h"
#include "Refureku/Misc/Visitor.h"

namespace rfk
{
	//Forward declarations
	class Entity;
	class Namespace;
	class ArchetypeAPI;
	class StructAPI;
	using ClassAPI = StructAPI;
	class EnumAPI;
	class FundamentalArchetypeAPI;
	class VariableAPI;
	class FunctionAPI;
	class MethodAPI;
	class StaticMethodAPI;
	class FieldAPI;
	class StaticFieldAPI;
	class EnumValueAPI;

	namespace internal
	{
		class DefaultEntityRegistererImpl;
		class ArchetypeRegistererImpl;
		class NamespaceFragmentRegistererImpl;
		class ClassTemplateInstantiationRegistererImpl;
	}

	class DatabaseAPI final
	{
		public:
			REFUREKU_INTERNAL DatabaseAPI()		noexcept;
			DatabaseAPI(DatabaseAPI const&)		= delete;
			DatabaseAPI(DatabaseAPI&&)			= delete;
			REFUREKU_INTERNAL ~DatabaseAPI()	noexcept;

			/**
			*	@brief Retrieve an entity by id.
			*
			*	@param id The id of the entity.
			*
			*	@return A constant pointer to the queried entity if it exists, else nullptr.
			*/
			RFK_NODISCARD REFUREKU_API Entity const*					getEntityById(std::size_t id)											const	noexcept;

			/**
			*	@brief Retrieve a namespace by id.
			*
			*	@param id The id of the namespace.
			*
			*	@return A constant pointer to the queried namespace if it exists, else nullptr.
			*/
			RFK_NODISCARD REFUREKU_API Namespace const*				getNamespaceById(std::size_t id)										const	noexcept;

			/**
			*	@brief	Retrieve a namespace by name.
			*			Can search nested namespaces directly using :: separator.
			*			Example: getNamespace("namespace1::namespace2") will get the namespace2 nested inside namespace1 if it exists.
			*
			*	@param name The name of the namespace.
			*
			*	@return A constant pointer to the queried namespace if it exists, else nullptr.
			*
			*	@exception BadNamespaceFormat if the provided namespace name has : instead of :: as a separator, or ends with :.
			*/
			RFK_NODISCARD REFUREKU_API Namespace const*				getNamespaceByName(char const* name)									const;

			/**
			*	@brief Execute the given visitor on all file level namespaces.
			* 
			*	@param visitor	Visitor function to call. Return false to abort the foreach loop.
			*	@param userData	Optional user data forwarded to the visitor.
			* 
			*	@return	The last visitor result before exiting the loop.
			*			If the visitor is nullptr, return false.
			* 
			*	@exception Any exception potentially thrown from the provided visitor.
			*/
			REFUREKU_API bool											foreachFileLevelNamespace(Visitor<Namespace> visitor,
																								  void*					userData)				const;

			/**
			*	@brief Retrieve an archetype by id.
			*
			*	@param id The id of the archetype.
			*
			*	@return A constant pointer to the queried archetype if it exists, else nullptr.
			*/
			RFK_NODISCARD REFUREKU_API ArchetypeAPI const*				getArchetypeById(std::size_t id)										const	noexcept;

			/**
			*	@brief	Retrieve a file level archetype by name.
			*			This method costs heavier performance as it will basically call getClassByName,
			*			getStructByName, getEnumByName and then getFundamentalArchetypeByName to find the queried archetype.
			*	
			*	@param archetypeName Name of the archetype.
			*
			*	@return A constant pointer to the queried archetype if it exists, else nullptr.
			*/
			RFK_NODISCARD REFUREKU_API ArchetypeAPI const*				getArchetypeByName(char const* name)									const	noexcept;

			/**
			*	@brief Retrieve a struct by id.
			*
			*	@param id The id of the struct.
			*
			*	@return A constant pointer to the queried struct if it exists, else nullptr.
			*/
			RFK_NODISCARD REFUREKU_API StructAPI const*					getStructById(std::size_t id)											const	noexcept;

			/**
			*	@brief Retrieve a file level struct by name.
			*
			*	@param name The name of the struct.
			*
			*	@return A constant pointer to the queried struct if it exists, else nullptr.
			*/
			RFK_NODISCARD REFUREKU_API StructAPI const*					getStructByName(char const* name)										const	noexcept;

			/**
			*	@brief Execute the given visitor on all file level structs.
			* 
			*	@param visitor	Visitor function to call. Return false to abort the foreach loop.
			*	@param userData	Optional user data forwarded to the visitor.
			* 
			*	@return	The last visitor result before exiting the loop.
			*			If the visitor is nullptr, return false.
			* 
			*	@exception Any exception potentially thrown from the provided visitor.
			*/
			REFUREKU_API bool											foreachFileLevelStruct(Visitor<StructAPI>	visitor,
																							   void*				userData)					const;

			/**
			*	@brief Retrieve a class by id.
			*
			*	@param id The id of the class.
			*
			*	@return A constant pointer to the queried class if it exists, else nullptr.
			*/
			RFK_NODISCARD REFUREKU_API ClassAPI const*					getClassById(std::size_t id)											const	noexcept;

			/**
			*	@brief Retrieve a file level class by name.
			*
			*	@param name The name of the class.
			*
			*	@return A constant pointer to the queried class if it exists, else nullptr.
			*/
			RFK_NODISCARD REFUREKU_API ClassAPI const*					getClassByName(char const* name)										const	noexcept;

			/**
			*	@brief Execute the given visitor on all file level classes.
			* 
			*	@param visitor	Visitor function to call. Return false to abort the foreach loop.
			*	@param userData	Optional user data forwarded to the visitor.
			* 
			*	@return	The last visitor result before exiting the loop.
			*			If the visitor is nullptr, return false.
			* 
			*	@exception Any exception potentially thrown from the provided visitor.
			*/
			REFUREKU_API bool											foreachFileLevelClass(Visitor<ClassAPI>	visitor,
																							  void*				userData)						const;

			/**
			*	@brief Retrieve an enum by id.
			*
			*	@param id The id of the enum.
			*
			*	@return A constant pointer to the queried enum if it exists, else nullptr.
			*/
			RFK_NODISCARD REFUREKU_API EnumAPI const*					getEnumById(std::size_t id)												const	noexcept;

			/**
			*	@brief Retrieve a file level enum by name.
			*
			*	@param name The name of the enum.
			*
			*	@return A constant pointer to the queried enum if it exists, else nullptr.
			*/
			RFK_NODISCARD REFUREKU_API EnumAPI const*					getEnumByName(char const* name)											const	noexcept;

			/**
			*	@brief Execute the given visitor on all file level enums.
			* 
			*	@param visitor	Visitor function to call. Return false to abort the foreach loop.
			*	@param userData	Optional user data forwarded to the visitor.
			* 
			*	@return	The last visitor result before exiting the loop.
			*			If the visitor is nullptr, return false.
			* 
			*	@exception Any exception potentially thrown from the provided visitor.
			*/
			REFUREKU_API bool											foreachFileLevelEnum(Visitor<EnumAPI>	visitor,
																							 void*				userData)						const;

			/**
			*	@brief Retrieve a fundamental archetype by id.
			*
			*	@param id The id of the fundamental archetype.
			*
			*	@return A constant pointer to the queried fundamental archetype if it exists, else nullptr.
			*/
			RFK_NODISCARD REFUREKU_API FundamentalArchetypeAPI const*	getFundamentalArchetypeById(std::size_t id)								const	noexcept;

			/**
			*	@brief Retrieve a fundamental archetype by name.
			*
			*	@param name The name of the fundamental archetype.
			*
			*	@return A constant pointer to the queried fundamental archetype if it exists, else nullptr.
			*/
			RFK_NODISCARD REFUREKU_API FundamentalArchetypeAPI const*	getFundamentalArchetypeByName(char const* name)							const	noexcept;

			/**
			*	@brief Retrieve a variable by id.
			*
			*	@param id The id of the variable.
			*
			*	@return A constant pointer to the queried variable if it exists, else nullptr.
			*/
			RFK_NODISCARD REFUREKU_API VariableAPI const*				getVariableById(std::size_t id)											const	noexcept;

			/**
			*	@brief Retrieve a file level (non-member) variable by name.
			*	
			*	@param name		The name of the variable.
			*	@param flags	Flags describing the queried variable.
			*					The result variable will have at least the provided flags.
			*	
			*	@return A constant pointer to the queried variable if it exists, else nullptr.
			*/
			RFK_NODISCARD REFUREKU_API VariableAPI const*				getVariableByName(char const* name,
																						  EVarFlags	flags = EVarFlags::Default)					const	noexcept;

			/**
			*	@brief Execute the given visitor on all file level variables.
			* 
			*	@param visitor	Visitor function to call. Return false to abort the foreach loop.
			*	@param userData	Optional user data forwarded to the visitor.
			* 
			*	@return	The last visitor result before exiting the loop.
			*			If the visitor is nullptr, return false.
			* 
			*	@exception Any exception potentially thrown from the provided visitor.
			*/
			REFUREKU_API bool											foreachFileLevelVariable(Visitor<VariableAPI>	visitor,
																								 void*					userData)				const;

			/**
			*	@brief Retrieve a function by id.
			*
			*	@param id The id of the function.
			*
			*	@return A constant pointer to the queried function if it exists, else nullptr.
			*/
			RFK_NODISCARD REFUREKU_API FunctionAPI const*				getFunctionById(std::size_t id)											const	noexcept;

			/**
			*	@brief Retrieve a file level (non-member) function by name.
			*	
			*	@param name		The name of the function.
			*	@param flags	Flags describing the queried function.
			*					The result function will have at least the provided flags.
			*	
			*	@return A constant pointer to the first function matching the name and flags if it exists, else nullptr.
			*/
			RFK_NODISCARD REFUREKU_API FunctionAPI const*				getFunctionByName(char const*		name,
																						  EFunctionFlags	flags = EFunctionFlags::Default)	const	noexcept;

			/**
			*	@brief Execute the given visitor on all file level functions.
			* 
			*	@param visitor	Visitor function to call. Return false to abort the foreach loop.
			*	@param userData	Optional user data forwarded to the visitor.
			* 
			*	@return	The last visitor result before exiting the loop.
			*			If the visitor is nullptr, return false.
			* 
			*	@exception Any exception potentially thrown from the provided visitor.
			*/
			REFUREKU_API bool											foreachFileLevelFunction(Visitor<FunctionAPI>	visitor,
																								 void*					userData)				const;

			/**
			*	@brief Retrieve a method by id.
			*
			*	@param id The id of the method.
			*
			*	@return A constant pointer to the queried method if it exists, else nullptr.
			*/
			RFK_NODISCARD REFUREKU_API MethodAPI const*					getMethodById(std::size_t id)											const	noexcept;

			/**
			*	@brief Retrieve a static method by id.
			*
			*	@param id The id of the static method.
			*
			*	@return A constant pointer to the queried static method if it exists, else nullptr.
			*/
			RFK_NODISCARD REFUREKU_API StaticMethodAPI const*			getStaticMethodById(std::size_t id)										const	noexcept;

			/**
			*	@brief Retrieve a field by id.
			*
			*	@param id The id of the field.
			*
			*	@return A constant pointer to the queried field if it exists, else nullptr.
			*/
			RFK_NODISCARD REFUREKU_API FieldAPI const*					getFieldById(std::size_t id)											const	noexcept;

			/**
			*	@brief Retrieve a static field by id.
			*
			*	@param id The id of the static field.
			*
			*	@return A constant pointer to the queried static field if it exists, else nullptr.
			*/
			RFK_NODISCARD REFUREKU_API StaticFieldAPI const*			getStaticFieldById(std::size_t id)										const	noexcept;

			/**
			*	@brief Retrieve an enum value by id.
			*
			*	@param id The id of the enum value.
			*
			*	@return A constant pointer to the queried enum value if it exists, else nullptr.
			*/
			RFK_NODISCARD REFUREKU_API EnumValueAPI const*				getEnumValueById(std::size_t id)										const	noexcept;

		private:
			//Forward declaration
			class DatabaseImpl;

			/** Pointer to the concrete Database implementation. */
			Pimpl<DatabaseImpl>	_pimpl;

			/**
			*	@brief	Get the singleton database instance.
			*			The method must be exported since it contains the singleton.
			* 
			*	@return The database singleton.
			*/
			REFUREKU_API static DatabaseAPI& getInstance() noexcept;

		friend internal::DefaultEntityRegistererImpl;
		friend internal::ArchetypeRegistererImpl;
		friend internal::NamespaceFragmentRegistererImpl;
		friend internal::ClassTemplateInstantiationRegistererImpl;
		friend REFUREKU_API DatabaseAPI const& getDatabaseAPI() noexcept;
	};

	/**
	*	@brief Get a reference to the database of this program.
	* 
	*	@return A reference to the database of this program.
	*/
	REFUREKU_API DatabaseAPI const& getDatabaseAPI() noexcept;
}