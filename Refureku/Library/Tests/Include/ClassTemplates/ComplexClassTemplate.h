#pragma once

#include "ClassTemplates/TestClassAB.h"

#include "Generated/ComplexClassTemplate.rfkh.h"

namespace rfk
{
	//Define a getArchetype method for the complex TEST::Vector type
	template <template <typename, template <typename, typename> typename, auto> typename T>
	rfk::Archetype const* getArchetype() noexcept
	{
		return nullptr;
	}
}

namespace NamespaceForTemplateClass
{
	template <typename T, template <typename A, typename B> typename U, int V>
	class RFKClass() Vector : public std::vector<T>
	{
		private:
		RFKField()
			int i;

		public:
		RFKField()
			typename T::Type t;

		RFKMethod()
			static void testStaticMethod(T const& t) {}

		//GENERATED CODE
		friend rfk::Struct;
		friend rfk::CodeGenerationHelpers;
		friend implements_template1__rfk_registerChildClass<Vector<T, U, V>, void, void(rfk::Struct&)>; 

		public: static rfk::Class const& staticGetArchetype() noexcept
		{
			static bool initialized = false;

			//TODO: Change Name without template types
			//TODO: Change combine hash of all archetypes
			static rfk::Class type("Vector<T, U, V>", 9918884327437644209u, sizeof(Vector<T, U, V>), true);

			if (!initialized)
			{
				initialized = true;

				type.setDefaultInstantiator(&rfk::defaultInstantiator<Vector<T, U, V>>);
				type.directParents.reserve(1);
				type.addToParents<std::vector<T>>(static_cast<rfk::EAccessSpecifier>(1));
				Vector<T, U, V>::_rfk_registerChildClass<Vector<T, U, V>>(type);
				[[maybe_unused]] rfk::Method* method = nullptr; [[maybe_unused]] rfk::StaticMethod* staticMethod = nullptr;
				staticMethod = type.addStaticMethod("testStaticMethod", 5430318730629265774u, rfk::Type::getType<void>(), std::make_unique<rfk::NonMemberFunction<void (const T &)>>(static_cast<void (*)(const T &)>(& Vector<T, U, V>::testStaticMethod)), static_cast<rfk::EMethodFlags>(25));
				staticMethod->parameters.reserve(1); staticMethod->addParameter("t", rfk::Type::getType<const T &>());
			}

			return type;
		}

		_RFK_UNPACK_IF_NOT_PARSING(private: static inline rfk::ArchetypeRegisterer _rfk_archetypeRegisterer = staticGetArchetype();)

		private: template <typename ChildClass> static void _rfk_registerChildClass(rfk::Struct& childClass) noexcept
		{
			rfk::CodeGenerationHelpers::registerChildClass<std::vector<T>, ChildClass>(childClass);
			rfk::Struct const& thisClass = staticGetArchetype();

			if constexpr (!std::is_same_v<ChildClass, Vector<T, U, V>>) const_cast<rfk::Struct&>(thisClass).subclasses.insert(&childClass);

			[[maybe_unused]] rfk::Field* field = nullptr;
			[[maybe_unused]] rfk::StaticField* staticField = nullptr;

			__RFK_DISABLE_WARNING_PUSH
				__RFK_DISABLE_WARNING_OFFSETOF

				field = childClass.addField("i", 2732867638607707709u, rfk::Type::getType<int>(), static_cast<rfk::EFieldFlags>(4), &thisClass, offsetof(ChildClass, i));
			field = childClass.addField("t", 2732870937142592342u, rfk::Type::getType<typename T::Type>(), static_cast<rfk::EFieldFlags>(1), &thisClass, offsetof(ChildClass, t));

			__RFK_DISABLE_WARNING_POP
		}

										  //Vector_T_U_V_GENERATED
	};
}

//class RFKClass() TestTemplateClass
//{
//	public:
//		RFKField()
//		NamespaceForTemplateClass::Vector<TestClassA, std::vector, 0>	vectorF;
//
//		RFKField()
//		NamespaceForTemplateClass::Vector<TestClassB, std::vector, 3>	vectorI;
//
//	TestTemplateClass_GENERATED
//};

File_ComplexClassTemplate_GENERATED

template class RFKClass() NamespaceForTemplateClass::Vector<TestClassA, std::vector, 0>;