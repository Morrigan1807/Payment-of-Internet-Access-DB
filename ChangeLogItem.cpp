#include "ChangeLogItem.h"

namespace PaymentofInternetAccess
{
	ChangeLogItem::ChangeLogItem(String^ table_count, String^ change_type)
	{
		this->table = table_count;
		this->change_type = change_type;
		primary_key = gcnew Dictionary<String^, String^>();
		column_name = gcnew List<String^>();
		value = gcnew List<String^>();
	}
	void ChangeLogItem::fill_primary_key_field(String^ primary_column, String^ primary_value)
	{
		primary_key->Add(primary_column, primary_value);
	}
	void ChangeLogItem::fill_row_update(String^ column_name, String^ value)
	{
		this->column_name->Add(column_name);
		this->value->Add(value);
	}
	void ChangeLogItem::applyChange()
	{
		String^ db = "Data Source=NIAGARA\\SQLEXPRESS;Initial Catalog=CourseProject;ApplicationIntent=ReadWrite;Integrated Security=SSPI";
		SqlConnection^ connect = gcnew SqlConnection(db);
		SqlCommand^ command = connect->CreateCommand();
		command->Connection = connect;
		String^ commandText;
		if (change_type == "DELETE")
		{
			commandText = "DELETE FROM " + table + " WHERE ";
			List<String^>^ primary_keys_check = gcnew List<String^>();
			for each (String^ key in primary_key->Keys)
			{
				primary_keys_check->Add(key + " = " + primary_key[key]);
			}
			commandText += primary_keys_check[0];
			for (int i = 1; i < primary_keys_check->Count; i++)
			{
				commandText += " AND " + primary_keys_check[i];
			}
		}
		if (change_type == "UPDATE")
		{
			commandText = "UPDATE " + table + " SET ";
			commandText += column_name[0] + " = " + value[0];
			for (int i = 1; i < column_name->Count; i++)
			{
				commandText += ", " + column_name[i] + " = " + value[i];
			}
			commandText += " WHERE ";
			List<String^>^ primary_keys_check = gcnew List<String^>();
			for each (String^ key in primary_key->Keys)
			{
				primary_keys_check->Add(key + " = " + primary_key[key]);
			}
			commandText += primary_keys_check[0];
			for (int i = 1; i < primary_keys_check->Count; i++)
			{
				commandText += " AND " + primary_keys_check[i];
			}
		}
		if (change_type == "INSERT")
		{
			commandText = "INSERT INTO " + table;
			commandText += "(" + column_name[0];
			for (int i = 1; i < column_name->Count; i++)
			{
				commandText += ", " + column_name[i];
			}
			commandText += ") VALUES ";
			commandText += "(" + value[0];
			for (int i = 1; i < value->Count; i++)
			{
				commandText += ", " + value[i];
			}
			commandText += ")";
		}
		command->CommandText = commandText;
		connect->Open();
		command->ExecuteNonQuery();
		connect->Close();
	}
}