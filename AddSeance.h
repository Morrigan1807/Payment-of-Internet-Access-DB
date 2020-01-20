#pragma once
#include "ChangeLogItem.h"

namespace PaymentofInternetAccess {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient;
	using namespace System::Xml;

	/// <summary>
	/// Сводка для AddSeance
	/// </summary>
	public ref class AddSeance : public System::Windows::Forms::Form
	{
	public:
		AddSeance(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
			String^ db = "Data Source=NIAGARA\\SQLEXPRESS;Initial Catalog=CourseProject;ApplicationIntent=ReadWrite;Integrated Security=SSPI";
			SqlConnection^ connect = gcnew SqlConnection(db);
			SqlCommand^ command = connect->CreateCommand();
			command->CommandText = "SELECT Computer_number From Computers";
			command->Connection = connect;
			SqlDataReader^ dr;
			connect->Open();
			dr = command->ExecuteReader();
			while (dr->Read())
			{
				this->computer_number->Items->Add(dr[0]);
			}
			dr->Close();
			command->CommandText = "SELECT ID_price From Prices";
			dr = command->ExecuteReader();
			while (dr->Read())
			{
				this->ID_price->Items->Add(dr[0]);
			}
			dr->Close();
			command->CommandText = "SELECT ID_connection From Connections";
			dr = command->ExecuteReader();
			while (dr->Read())
			{
				this->ID_connection->Items->Add(dr[0]);
			}
			dr->Close();
			connect->Close();
			
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~AddSeance()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  exit;
	protected:

	private: System::Windows::Forms::Button^  Add_row;
	protected:

	private: System::Windows::Forms::Label^  label5;

	private: System::Windows::Forms::Label^  label4;

	private: System::Windows::Forms::Label^  label3;



	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label1;

	private: System::Windows::Forms::Label^  label6;

	public: Form^ general;
	private: System::Windows::Forms::DateTimePicker^  dateTimePicker1;
	private: System::Windows::Forms::ComboBox^  computer_number;
	private: System::Windows::Forms::ComboBox^  ID_connection;
	private: System::Windows::Forms::ComboBox^  Operator_number;
	private: System::Windows::Forms::ComboBox^  ID_price;
	private: System::Windows::Forms::ComboBox^  ID_shift;

	private: System::ComponentModel::IContainer^  components;
	public:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(AddSeance::typeid));
			this->exit = (gcnew System::Windows::Forms::Button());
			this->Add_row = (gcnew System::Windows::Forms::Button());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->dateTimePicker1 = (gcnew System::Windows::Forms::DateTimePicker());
			this->computer_number = (gcnew System::Windows::Forms::ComboBox());
			this->ID_connection = (gcnew System::Windows::Forms::ComboBox());
			this->Operator_number = (gcnew System::Windows::Forms::ComboBox());
			this->ID_price = (gcnew System::Windows::Forms::ComboBox());
			this->ID_shift = (gcnew System::Windows::Forms::ComboBox());
			this->SuspendLayout();
			// 
			// exit
			// 
			this->exit->Location = System::Drawing::Point(198, 323);
			this->exit->Name = L"exit";
			this->exit->Size = System::Drawing::Size(75, 23);
			this->exit->TabIndex = 35;
			this->exit->Text = L"Выйти";
			this->exit->UseVisualStyleBackColor = true;
			this->exit->Click += gcnew System::EventHandler(this, &AddSeance::exit_Click);
			// 
			// Add_row
			// 
			this->Add_row->Location = System::Drawing::Point(12, 323);
			this->Add_row->Name = L"Add_row";
			this->Add_row->Size = System::Drawing::Size(115, 23);
			this->Add_row->TabIndex = 34;
			this->Add_row->Text = L"Добавить строку";
			this->Add_row->UseVisualStyleBackColor = true;
			this->Add_row->Click += gcnew System::EventHandler(this, &AddSeance::Add_row_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::Color::Transparent;
			this->label5->Location = System::Drawing::Point(25, 203);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(50, 13);
			this->label5->TabIndex = 33;
			this->label5->Text = L"ID цены:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::Transparent;
			this->label4->Location = System::Drawing::Point(25, 252);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(100, 13);
			this->label4->TabIndex = 31;
			this->label4->Text = L"Номер оператора:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->Location = System::Drawing::Point(25, 112);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(84, 13);
			this->label3->TabIndex = 29;
			this->label3->Text = L"ID соединения:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Location = System::Drawing::Point(25, 66);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(36, 13);
			this->label2->TabIndex = 26;
			this->label2->Text = L"Дата:";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Location = System::Drawing::Point(25, 17);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(110, 13);
			this->label1->TabIndex = 25;
			this->label1->Text = L"Номер компьютера:";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->BackColor = System::Drawing::Color::Transparent;
			this->label6->Location = System::Drawing::Point(25, 153);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(58, 13);
			this->label6->TabIndex = 37;
			this->label6->Text = L"ID смены:";
			// 
			// dateTimePicker1
			// 
			this->dateTimePicker1->Format = System::Windows::Forms::DateTimePickerFormat::Short;
			this->dateTimePicker1->Location = System::Drawing::Point(28, 82);
			this->dateTimePicker1->Name = L"dateTimePicker1";
			this->dateTimePicker1->Size = System::Drawing::Size(220, 20);
			this->dateTimePicker1->TabIndex = 27;
			this->dateTimePicker1->Value = System::DateTime(2019, 5, 11, 18, 43, 48, 0);
			this->dateTimePicker1->ValueChanged += gcnew System::EventHandler(this, &AddSeance::dateTimePicker1_ValueChanged);
			// 
			// computer_number
			// 
			this->computer_number->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->computer_number->Location = System::Drawing::Point(28, 33);
			this->computer_number->Name = L"computer_number";
			this->computer_number->Size = System::Drawing::Size(220, 21);
			this->computer_number->TabIndex = 38;
			// 
			// ID_connection
			// 
			this->ID_connection->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->ID_connection->Location = System::Drawing::Point(28, 128);
			this->ID_connection->Name = L"ID_connection";
			this->ID_connection->Size = System::Drawing::Size(220, 21);
			this->ID_connection->TabIndex = 39;
			// 
			// Operator_number
			// 
			this->Operator_number->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->Operator_number->Location = System::Drawing::Point(28, 268);
			this->Operator_number->Name = L"Operator_number";
			this->Operator_number->Size = System::Drawing::Size(220, 21);
			this->Operator_number->TabIndex = 40;
			// 
			// ID_price
			// 
			this->ID_price->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->ID_price->Location = System::Drawing::Point(28, 219);
			this->ID_price->Name = L"ID_price";
			this->ID_price->Size = System::Drawing::Size(220, 21);
			this->ID_price->TabIndex = 41;
			// 
			// ID_shift
			// 
			this->ID_shift->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->ID_shift->Location = System::Drawing::Point(28, 169);
			this->ID_shift->Name = L"ID_shift";
			this->ID_shift->Size = System::Drawing::Size(220, 21);
			this->ID_shift->TabIndex = 42;
			this->ID_shift->SelectionChangeCommitted += gcnew System::EventHandler(this, &AddSeance::ID_shift_SelectionChangeCommitted);
			// 
			// AddSeance
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(285, 377);
			this->Controls->Add(this->ID_shift);
			this->Controls->Add(this->ID_price);
			this->Controls->Add(this->Operator_number);
			this->Controls->Add(this->ID_connection);
			this->Controls->Add(this->computer_number);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->exit);
			this->Controls->Add(this->Add_row);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->dateTimePicker1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"AddSeance";
			this->Text = L"Добавить сеанс";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &AddSeance::AddSeance_FormClosed);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
private: System::Void Add_row_Click(System::Object^  sender, System::EventArgs^  e) 
{
	if (computer_number->Text != "" && ID_connection->Text != "" && Operator_number->Text != "" && ID_price->Text != "" && ID_shift->Text != "")
	{
		ChangeLogItem^ ch = gcnew ChangeLogItem("Seance", "INSERT");
		ch->fill_row_update("Computer_number", this->computer_number->Text);
		ch->fill_row_update("S_date", "CONVERT(DATE,\'" + this->dateTimePicker1->Text + "\',104)");
		ch->fill_row_update("ID_connection", this->ID_connection->Text);
		ch->fill_row_update("Operator_number", this->Operator_number->Text);
		ch->fill_row_update("ID_price", this->ID_price->Text);
		ch->fill_row_update("ID_shift", this->ID_shift->Text);
		ch->applyChange();
		MessageBox::Show("Строка успешно добавлена!");
	}
	else
	{
		MessageBox::Show("Ошибка! Все поля должны быть заполнены!");
	}
}
private: System::Void exit_Click(System::Object^  sender, System::EventArgs^  e) 
{
	general->Enabled = true;
	this->Close();
}
private: System::Void AddSeance_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e) 
{
	general->Enabled = true;
}
private: System::Void dateTimePicker1_ValueChanged(System::Object^  sender, System::EventArgs^  e) 
{
	this->ID_shift->Items->Clear();
	String^ db = "Data Source=NIAGARA\\SQLEXPRESS;Initial Catalog=CourseProject;ApplicationIntent=ReadWrite;Integrated Security=SSPI";
	SqlConnection^ connect = gcnew SqlConnection(db);
	SqlCommand^ command = connect->CreateCommand();
	command->CommandText = "SELECT DISTINCT ID_shift From Shifts WHERE DATEDIFF(DAY,DT_start,\'"
		+ dateTimePicker1->Text->ToString() + "\') = 0 OR DATEDIFF(DAY,DT_end,\'" + dateTimePicker1->Text->ToString()
		+ "\') = 0";
	command->Connection = connect;
	SqlDataReader^ dr;
	connect->Open();
	dr = command->ExecuteReader();
	while (dr->Read())
	{
		this->ID_shift->Items->Add(dr[0]);
	}
	dr->Close();
	connect->Close();
}
private: System::Void ID_shift_SelectionChangeCommitted(System::Object^  sender, System::EventArgs^  e) 
{
	this->Operator_number->Items->Clear();
	String^ db = "Data Source=NIAGARA\\SQLEXPRESS;Initial Catalog=CourseProject;ApplicationIntent=ReadWrite;Integrated Security=SSPI";
	SqlConnection^ connect = gcnew SqlConnection(db);
	SqlCommand^ command = connect->CreateCommand();
	command->CommandText = "SELECT Operator_number From Shift_operators Where ID_shift = " + ID_shift->Text->ToString();
	command->Connection = connect;
	SqlDataReader^ dr;
	connect->Open();
	dr = command->ExecuteReader();
	while (dr->Read())
	{
		this->Operator_number->Items->Add(dr[0]);
	}
	dr->Close();
	connect->Close();
}
};
}
