#pragma once
namespace PaymentofInternetAccess 
{
	using namespace System;
	using namespace System::Collections;
	using namespace System::Data;
	using namespace System::Data::SqlClient;
	using namespace System::Xml;
	using namespace System::Collections::Generic; 
	ref class ChangeLogItem
	{
	private:
		String^ table;
		String^ change_type;
		Dictionary<String^, String^>^ primary_key;
		List<String^>^ column_name;
		List<String^>^ value;
	public:
		ChangeLogItem(String^, String^);
		void fill_primary_key_field(String^, String^);
		void fill_row_update(String^, String^);
		void applyChange();
	};
}